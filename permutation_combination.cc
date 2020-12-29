#include <iostream>
#include <vector>

using namespace std;

void Perm(vector<int>& map, vector<int>& res, int m, int n, int current) {
	if (current == n) {
		for (auto it: res)
			cout << it << ' ';
		cout << endl;
	} else {
		for (int i = 0; i < m; ++i) {
			if (map[i] == 0) {
				map[i] = 1;
				res.push_back(i + 1);
				Perm(map, res, m, n, current + 1);
				map[i] = 0;
				res.pop_back();
			}	
		}
	}
}

void Comb(vector<int>& res, int m, int n, int current, int start) {
	if (current == n) {
		for (auto it: res)
			cout << it << ' ';
		cout << endl;
	} else {
		for (int i = start; i < m + 1 - n + current; ++i) {
			res.push_back(i + 1);
			Comb(res, m, n, current + 1, i + 1);
			res.pop_back();
		}
	}
}

int main() {
	int m, n;
	char opt;
	cout << "Please enter A for permutation or C for combination: ";
	cin >> opt;
	cout << "Please enter m and n: " << endl;
	cin >> m >> n;
	vector<int> map(m, 0);
	vector<int> res;
	if (opt == 'A')
		Perm(map, res, m, n, 0);
	else
		Comb(res, m, n, 0, 0);
	return 0;
}
