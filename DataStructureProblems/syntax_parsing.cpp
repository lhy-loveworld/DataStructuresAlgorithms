#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
	ifstream myfile;
	myfile.open("syntax_parsing.txt");
	stack <char> symbols;
	char symbol;
	bool success = true;
	while (myfile.get(symbol)) {
		switch (symbol) {
			case '(':
			case '{':
			case '[': {
				symbols.push(symbol);
				continue;
			}
			case ')': {
				if (symbols.empty()) {
					success = false;
					break;
				} else {
					if (symbols.top() != '(') {
						success = false; 
						break;
					} else {
						symbols.pop();
						continue;
					}
				}
			}
			case ']': {
				if (symbols.empty()) {
					success = false;
					break;
				} else {
					if (symbols.top() != '[') {
						success = false; 
						break;
					} else {
						symbols.pop();
						continue;
					}
				}
			}
			case '}': {
				if (symbols.empty()) {
					success = false;
					break;
				} else {
					if (symbols.top() != '{') {
						success = false; 
						break;
					} else {
						symbols.pop();
						continue;
					}
				}
			}
			case '/': {
				char next;
				myfile.get(next);
				if (next == '/') {
					cout<<123;
					myfile.get(next);
					while (next!='\n') myfile.get(next);
					break;
				} else 
					if (next == '*') {
						myfile.get(symbol);
						while (symbol!=EOF) {
							if (symbol=='*') {
								myfile.get(next);
								if (next=='/') break;
								else myfile.putback(next);
							}
							myfile.get(symbol);
						}
						if (symbol == EOF) {
							success == false;
							break;
						} else continue;
					} else {
						myfile.putback(next);
						continue;
					}
				break;
			}
		}
	}

	if (success) {
		if (!symbols.empty()) cout<<"Too much left symbols!"<<endl;
		else cout<<"Success!"<<endl;
	} else cout<<"Not match!"<<endl;
	myfile.close();
	return 0;
}