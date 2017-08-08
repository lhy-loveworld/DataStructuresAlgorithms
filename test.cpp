#include <iostream>

using namespace std;

int main () {
	int a = 0, b = 0, c = 0;
	int n[10] = {1, 2, 3, 4, 2, 3, 4, 1, 5, 3};
	for (int i = 0; i < 10; ++i) {
		c = ~a & ((b & ~c & n[i]) | (~b & c & ~n[i]));
		b = ~c & ((a & ~b & n[i]) | (~a & b & ~n[i]));
		a = (a ^ n[i]) & ~b & ~c;
	}
	cout << c;
	return 0;
}