#include <iostream>

using namespace std;

void adds(int a) {
	a++;
	cout << a;
}
int main () {
	int i = 10;
	adds(i);
	return 0;
}