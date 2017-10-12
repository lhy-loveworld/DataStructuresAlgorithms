//Arthor: lhy-loveworld
//Method: using stack
//Complexity: time O(N), space O(N)

#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <cmath>

using namespace std;

char* getnextoprt(int, char*);

class calc {
	char* exp;
	stack <int> oprds;
	stack <char> oprts;
 public:
	calc(string);
	~calc() {delete exp;}
	int result();
	void binaryop(char);
};

calc::calc(string str) {
	exp = new char [str.length()+1];
	strcpy(exp,str.c_str());
}

void calc::binaryop(char oprt) {
	int oprd1 = 0;
	int oprd2 = 0;
	oprts.pop();
	oprd1 = oprds.top();
	oprds.pop();
	oprd2 = oprds.top();
	oprds.pop();
	switch (oprt) {
		case '+':{
			oprds.push(oprd2 + oprd1);
			break;
		}
		case '-': {
			oprds.push(oprd2 - oprd1);
			break;
		}
		case '*': {
			oprds.push(oprd2 * oprd1);
			break;
		}
		case '/': {
			oprds.push(oprd2 / oprd1);
			break;
		}
		case '^': {
			oprds.push(pow(oprd2, oprd1));
			break;
		}	
	}
}

int calc::result() {
	char oprt = exp[0];
	char* remaining = exp;
	while (*remaining!='\0') {
		if ((oprt >= '0') && (oprt <= '9')) {
			int num = atoi(remaining);
			oprds.push(num);
			while (((oprt >= '0') && (oprt <= '9'))||(oprt == ' ')) {
				++remaining;
				oprt = remaining[0];
			}
		} else {
			switch (oprt) {
				case '(': {
					oprts.push(oprt);
					break;
				}
				case '-':
				case '+': {
					while ((!oprts.empty()) && (oprts.top() != '(')) {
						binaryop(oprts.top());
					}
					oprts.push(oprt);
					break;
				}
				case '*':
				case '/': {
					while ((!oprts.empty()) && (oprts.top() != '(') && (oprts.top() != '+') && (oprts.top() != '-')) {
						binaryop(oprts.top());
					}
					oprts.push(oprt);
					break;
				}
				case '^': {
					while ((!oprts.empty()) && (oprts.top() == '^')) {
						binaryop(oprts.top());
					}
					oprts.push(oprt);
					break;
				}
				case ')': {
					while ((!oprts.empty()) && (oprts.top() != '(')) {
						binaryop(oprts.top());
					}
					oprts.pop();
					break;
				}
			}
			++remaining;
			oprt = remaining[0];
			while (oprt == ' ') {
				remaining++;
				oprt = remaining[0];	
			}
		}
	}
	while (!oprts.empty()) binaryop(oprts.top());
	return oprds.top();
}


int main() {
	string str;
	getline(cin,str);
	calc c1(str);
	cout << c1.result();
	return 0;
}