#include <iostream>
#include <vector>

using namespace std;

bool comb(vector<int>& res, int m, int n) {
	int i = n - 1;
	do {
		res[i]++;
	} while (res[i] > m - n + i && i--);
	if (res[0] > m - n)
		return false;
	while (i++ < n)
		res[i] = res[i - 1] + 1;
	return true;
}

int main() {
	int m, n;
	cout << "Please enter m and n: " << endl;
	cin >> m >> n;
	vector<int> res(n, 0);
	for (int i = 0; i < n; ++i) {
		res[i] = i;
	}
	do {
		for (int i = 0; i < n; ++i) {
			cout << res[i] + 1 << ((i == n - 1) ? '\n' : ' ');
		}
	} while (comb(res, m, n));
	return 0;
}