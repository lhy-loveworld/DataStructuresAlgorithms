//Arthor: lhy-loveworld
//Method: stack, binary tree
//Complexity: time: O(N) space: O(N)

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

class calc {
	char* expr;
	struct node {
		char oprt;
		int data;
		node* left;
		node* right;
		node(char op = '\0', int d=0, node *l = NULL, node *r = NULL) {oprt = op; data = d; left = l; right = r;}
	};
 private:
	node *subtree(char *);
	node *add_node(node *, node *);
	int post_order(node *);
	void clear();
	void clear(node *);
 public:
	node *root = NULL;
	calc(string);
	~calc() {clear();};
	int result();
	void build_tree();
	void print(node *);
};

calc::calc(string str) {
	expr = new char [str.length() + 1];
	strcpy(expr, str.c_str());
}

void calc::clear() {
	delete[] expr;
	clear(root);
}

void calc::clear(calc::node *t) {
	if (t->left != NULL) clear(t->left);
	if (t->right != NULL) clear(t->right);
	delete t;
}

void calc::build_tree() {
	root = subtree(expr);
}

calc::node *calc::add_node(calc::node *parent, calc::node *child) {
	if (parent == NULL) parent = child;
	else {
		calc::node *current = parent;
		while (current->right!=NULL) current = current->right;
		current->right = child;
	}
	return parent;
}

calc::node *calc::subtree(char *exp) {
	calc::node *sub_tree = NULL;
	bool brack = false;
	while (exp[0]) {
		//cout<<"exp"<<exp<<endl;
		if (exp[0]=='(') {
			stack<char> brc;
			brc.push(exp[0]);
			int l = 0;
			while (!brc.empty()) {
				l++;
				if (exp[l] == '(') brc.push(exp[0]);
				else
					if (exp[l] == ')') brc.pop();
			}
			char* sub_exp = new char [l];
			strncpy(sub_exp, exp+1, l-1);
			sub_exp[l-1] = '\0';
			//cout<<"sub_exp"<<sub_exp<<endl;
			sub_tree = add_node(sub_tree, subtree(sub_exp));
			brack = true;
			exp+=l+1;
		} else
				if ((exp[0]<='9')&&(exp[0]>='0')) {
					int val = exp[0] - '0';
					exp++;
					while ((exp[0]<='9')&&(exp[0]>='0')) {
						val = val * 10 + exp[0] - '0';
						exp++;
					}
					calc::node *leaf = new node;
					leaf->data = val;
					sub_tree = add_node(sub_tree, leaf);
				} else
						if ((exp[0] == '+')||(exp[0] == '-')) {
							calc::node *new_root = new node;
							new_root->oprt = exp[0];
							new_root->left = sub_tree;
							sub_tree = new_root;
							exp++;
						} else
								if ((exp[0] == '*')||(exp[0] == '/')) {
									if ((brack == false) && ((sub_tree->oprt == '+')||(sub_tree->oprt == '-'))) {
										calc::node *new_right = new node;
										new_right->oprt = exp[0];
										new_right->left = sub_tree->right;
										sub_tree->right = new_right;
										exp++;
									} else {
											calc::node *new_root = new node;
											new_root->oprt = exp[0];
											new_root->left = sub_tree;
											sub_tree = new_root;
											exp++;
										}
									brack == false;
								}
		else exp++;
		cout<<sub_tree->data<<sub_tree->oprt<<"exp"<<exp<<endl;
	}
	return sub_tree;
}

int calc::result() {
	return post_order(root);
}

int calc::post_order(calc::node *N) {
	if (N->oprt == '\0') return N->data;
	else switch (N->oprt) {
		case '+': return post_order(N->left)+post_order(N->right);
		case '-': return post_order(N->left)-post_order(N->right);
		case '*': return post_order(N->left)*post_order(N->right);
		case '/': return post_order(N->left)/post_order(N->right);
	}
}

void calc::print(calc::node *N) {
	cout<<N->oprt<<N->data<<endl;
}

int main() {
	calc c1("(4+5)*(8+9)+10");
	c1.build_tree();
	c1.print(c1.root->left->right);
	cout<<c1.result()<<endl;
	/*char ch[] = "1234";
	char* c = ch;
	while (c[0]) cout<<(c++)<<endl;*/
	return 0;
}