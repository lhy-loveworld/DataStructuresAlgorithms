//Arthor: lhy-loveworld
//Method: Different sort algorithms

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <list>
#include <queue>

using namespace std;

struct comparator
{
	bool operator()(int i, int j)
	{
		return i<j;
	}
};

void build_vector(string, vector<int> &);

void build_list(string, list<int> &);

void print_vector(vector<int>);

void print_list(list<int>);

void simple_insertion_sort(vector<int> &); //O(N^2) suitable for small data, and almost sorted

void binary_insertion_sort(vector<int> &); //worst case O(N^2) same as simple insertion sort

int binary_search(vector<int> &, int, int, int);

void shellsort(vector<int> &); //worst case O(N^2), average case O(N^(3/2)) suitable for medium data

void simple_selection_sort(vector<int> &); //O(N^2) same as simple insertion sort

void heapsort(list<int> &); //O(Nlog(N)) 

void bubblesort(vector<int> &); //best case O(N), worst case O(N^2), suitable for almost sorted data

void quicksort(vector<int> &, int, int); //best case O(Nlog(N)), average case O(Nlog(N)), worst case (N^2)

int divide(vector<int> &, int, int);

void mergesort(vector<int> &, int, int); // O(Nlog(N)), need additional space

void merge(vector<int> &, int, int);


int main()
{
	string seq_s;
	vector<int> seq_v;
	list<int> seq_l;
	getline(cin, seq_s);
	build_list(seq_s, seq_l);
	heapsort(seq_l);
	print_list(seq_l);
	//build_vector(seq_s, seq_v);
	//mergesort(seq_v, 0, seq_v.size() - 1);
	//quicksort(seq_v, 0, seq_v.size() - 1);
	//bubblesort(seq_v);
	//shellsort(seq_v);
	//binary_insertion_sort(seq);
	//simple_insertion_sort(seq);
	//print_vector(seq_v);
	return 0;
}

void build_vector(string s, vector<int> &v)
{
	char* cnumin = new char [s.length()+1];
	strcpy(cnumin, s.c_str());
	char* nextnum = strtok(cnumin, " ");
	while (nextnum != NULL)
	{
		v.push_back(atoi(nextnum));
		nextnum = strtok(NULL, " ");
	}
	delete[] cnumin;
}

void build_list(string s, list<int> &l)
{
	char* cnumin = new char [s.length()+1];
	strcpy(cnumin, s.c_str());
	char* nextnum = strtok(cnumin, " ");
	while (nextnum != NULL)
	{
		l.push_back(atoi(nextnum));
		nextnum = strtok(NULL, " ");
	}
	delete[] cnumin;
}

void print_vector(vector<int> v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); it++) cout << ' ' << *it;
  	cout << '\n';
}

void print_list(list<int> l)
{
	list<int>::iterator it;
	for (it = l.begin(); it != l.end(); it++) cout << ' ' << *it;
  	cout << '\n';
}

void simple_insertion_sort(vector<int> &v)
{
	for (int i = 1; i < v.size(); ++i)
	{
		int temp = v[i];
		int j;
		for (j = i-1; (v[j] > temp)&&(j >= 0); j--) v[j+1] = v[j];
		v[j+1] = temp;
	}
}

void binary_insertion_sort(vector<int> &v)
{
	for (int i = 1; i <v.size(); ++i)
	{
		int temp = v[i];
		int j = binary_search(v, 0, i-1, temp);
		for (int k = i - 1; k >= j; k--) v[k+1] = v[k];
		v[j] = temp;
	}
}

int binary_search(vector<int> &v, int l, int h, int d)
{
	if (l == h)
		if (v[l] > d) return l;
		else return l+1;
	else
	{
		int mid = (l + h) / 2;
		if (v[mid] > d) return binary_search(v, l, mid, d);
		else return binary_search(v, mid+1, h, d);
	}
}

void shellsort(vector<int> &v)
{
	int gap = v.size();
	do
	{
		gap = gap/2;
		for (int i = 0; i < gap; ++i)
		{
			for (int j = i + gap; j < v.size(); j+=gap)
			{
				int temp = v[j];
				int k;
				for (k = j-gap; (v[k] > temp)&&(k >= 0); k-=gap) v[k + gap] = v[k];
				v[k+gap] = temp;
			}
		}		
	} while (gap > 1);
}

void simple_selection_sort(vector<int> &v)
{
	int min;
	for (int i = 0; i < v.size(); ++i)
	{
		min = v[i];
		int k = i;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < min)
			{
				min = v[j];
				k = j;
			}
		}
		v[k] = v[i];
		v[i] = min;
	}
}

void heapsort(list<int> &l)
{
	priority_queue <int, vector<int>, comparator> minHeap;
	while (!l.empty())
	{
		minHeap.push(l.back());
		l.pop_back();
	}
	while (!minHeap.empty())
	{
		l.push_back(minHeap.top());
		minHeap.pop();
	}
}

void bubblesort(vector<int> &v)
{
	int temp;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		for (int j = 0; j < v.size() - 1 - i; ++j)
		{
			if (v[j] > v[j+1])
			{
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}

void quicksort(vector<int> &v, int l, int h)
{
	if (h > l)
	{
		int mid = divide(v, l, h);
		quicksort(v, l, mid - 1);
		quicksort(v, mid + 1, h);
	}
}

int divide(vector<int> &v, int l, int h)
{
	int temp = v[l];
	while (l!=h)
	{
		while ((v[h] >= temp)&&(l != h)) h--;
		v[l] = v[h];
		while ((v[l] <= temp)&&(l != h)) l++;
		v[h] = v[l];
	}
	v[l] = temp;
	return l;
}

void mergesort(vector<int> & v, int l, int h)
{
	if (l != h)
	{
		mergesort(v, l, (l + h)/2);
		mergesort(v, (l + h)/2 + 1, h);
		merge(v, l, h);
	}
}

void merge(vector<int> & v, int l, int h)
{
	int tmp[h-l+1];
	int i = l;
	int j = (l + h)/2 + 1;
	for (int k = 0; k < h-l+1; ++k)
	{
		if (j>h) {tmp[k] = v[i];i++;}
		else if (i>(l + h)/2) {tmp[k] = v[j];j++;}
			else if (v[i]<v[j]) {tmp[k] = v[i];i++;}
				else {tmp[k] = v[j];j++;}
	}
	for (int k = l; k < h+1; ++k)
	{
		v[k] = tmp[k-l];
	}
}