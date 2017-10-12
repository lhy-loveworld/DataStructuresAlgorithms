//Arthor: lhy-loveworld
//Method: use 3 methods to convert a string to int, use dp to get maximum subsequence
//Complexity: Time: O(N) Space: O(N)

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

struct node {
	int val;
	node* n_ptr = NULL;
};

int main() {
	string numin;
	node* head = NULL;
	node* current = NULL;
	getline(cin,numin);
	
//---------------------------------------------------------	
/*//Method 1: using istringstream, the slowest one	
	istringstream iss(numin);
	int num;
	head = new node;
	current = head;
	while (iss >> num) {
		current->n_ptr = new node;
		current = current->n_ptr;
		current->val = num;
	}*/

/*Method 2: using strstr and atoi function, the same speed as method 3
	char* cnumin = new char [numin.length()+1];
	strcpy(cnumin, numin.c_str());
	char* loc = cnumin;	//location
	head = new node;
	current = head;
	while (loc != NULL) {
		current->n_ptr = new node;
		current = current->n_ptr;
		current->val = atoi(loc);	//atoi first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value. 
		loc = strstr(loc+1," ");	//strstr returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
	}*/

//Method 3: using strtok and atoi function	
	char* cnumin = new char [numin.length()+1];
	strcpy(cnumin, numin.c_str());
	head = new node;
	current = head;
	char* nextnum = strtok(cnumin, " ");	//If a token is found, a pointer to the beginning of the token. Otherwise, a null pointer.
	while (nextnum != NULL) {
		current->n_ptr = new node;
		current = current->n_ptr;
		current->val = atoi(nextnum);	//atoi first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value. 
		nextnum = strtok(NULL, " ");	//a null pointer may be specified, in which case the function continues scanning where a previous successful call to the function ended.
	}
//-------------------------------------------------------

	current = head;
	int maxsum = 0;
	int thissum = 0;
	node* maxbegin = NULL;
	node* maxend = NULL;
	node* thisbegin = NULL;
	while (current->n_ptr != NULL) {
		current = current->n_ptr;
		thissum = thissum + current->val;
		if (current->val > 0) {
			if (thisbegin == NULL) 	thisbegin = current;
			if (thissum > maxsum) {
				maxsum = thissum;
				maxbegin = thisbegin;
				maxend = current;
			}
		} else {
				if (thissum <= 0) {
					thissum = 0;
					thisbegin = NULL;
				}
			}
	}
	current = maxbegin;
	while (current != maxend) {
		cout << current->val <<' ';
		current = current->n_ptr;
	}
	cout << current->val <<endl;
	cout << maxsum << endl;
	return 0;
}
