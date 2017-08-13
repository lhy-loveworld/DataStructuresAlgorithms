#include <iostream>

using namespace std;

int main () {
	int i = 10;
	do ;
	while ( 1 == 0 && i--);
	
	cout << i;
	return 0;
}