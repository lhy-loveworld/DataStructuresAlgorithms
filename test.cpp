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
	te.push_front(1);
	if (it == te.begin()) cout << te.front() << te.back();
	return 0;
}