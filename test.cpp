#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
	list<int> te;
	te.push_front(1);
	
	list<int>::iterator it = te.begin();
	te.push_front(2);
	te.erase(it);
	cout << *it;
	return 0;
}