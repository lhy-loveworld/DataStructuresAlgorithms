//Arthor: lhy-loveworld

//Method: As for this dictionary requires prefix searching, the best way to implement is a binary search tree.
//		    As for the time is limited, I will implement through the simplest binary search tree, rather than AVL trees or red-black trees
//				For prefix retrieving, we first determine the searching direction (left or right or both), then just recursively call the function

//Test function: Insert(char *word, char *definition)
//							 Delete(char *word)
//							 GetDef(char *word)
//							 PrefixRetr(char *prefix)

//Need to be modified: should have used recursion to do Insert, Delete and GetDef.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Dictionary {
	struct Node {
		Node *left, *right;
		char *Word;
		char *Definition;
		Node(): left(NULL), right(NULL), Word(NULL), Definition(NULL) {}
		Node(char *w, char *d, Node *L = NULL, Node *R = NULL) 
			{left = L; right = R; Word = new char [strlen(w)]; strcpy(Word, w); Definition = new char [strlen(d)]; strcpy(Definition,d);}
		~Node(){} 
	};
	Node *root;

 private:
 	Node** Find(char *, Node * &);
 	void clear();
 	void clear(Node *);
 	void Delete(Node ** &);
 	bool PrefixPrint(Node *, char *);

 public:
 	Dictionary(): root(NULL) {}
 	~Dictionary() {clear();}
 	void Insert(char *, char *);
 	void Delete(char *);
 	void PrefixRetr(char *);
 	void GetDef(char *);
}; //class Dictionary

void Dictionary::clear() {
	if (root != NULL) clear(root);
	root = NULL;
} //clear the whole tree

void Dictionary::clear(Node *t) {
	if (t->left != NULL) clear(t->left);
	if (t->right != NULL) clear(t->right);
	delete[] t->Word;
	delete[] t->Definition;
	delete t;
} //clear a specific node

Dictionary::Node** Dictionary::Find(char *w, Dictionary::Node * &t) {
	if (t == NULL || strcmp(w, t->Word) == 0) return &t;
	if (strcmp(w, t->Word) < 0) return Find(w, t->left);
	if (strcmp(w, t->Word) > 0) return Find(w, t->right);
}	//find a node with word as its key

void Dictionary::Delete(Dictionary::Node ** &t) {
	if ((*t)->left == NULL && (*t)->right == NULL) {
		delete[] (*t)->Word;
		delete[] (*t)->Definition;
		delete *t;
		*t == NULL;
	} else {
		if ((*t)->right == NULL) {
			delete[] (*t)->Word;
			delete[] (*t)->Definition;
			*t = (*t)->left;
		} else {
			if ((*t)->left == NULL) {
				delete[] (*t)->Word;
				delete[] (*t)->Definition;
				*t = (*t)->right;
			} else {
				cout<<123;
				Dictionary::Node **tmp = &((*t)->right);
				while ((*tmp)->left != NULL) tmp = &((*tmp)->left);
				delete[] (*t)->Word;
				delete[] (*t)->Definition;
				(*t)->Word = new char [strlen((*tmp)->Word)];
				(*t)->Definition = new char [strlen((*tmp)->Definition)];
				strcpy((*t)->Word, (*tmp)->Word);
				strcpy((*t)->Definition, (*tmp)->Definition);
				Delete(tmp);
			}
		}
	}
}	//delete a specific node


void Dictionary::Insert(char *w, char *d) {
	if (root == NULL) {
		root = new Node(w, d);
	} else {
		Dictionary::Node *t = root;
		while (strcmp(w, t->Word)) {
			if (strcmp(w, t->Word) < 0) {
				if (t->left == NULL) {
					t->left = new Node(w, d);
					return;
				} else t = t->left;
			} else {
				if (t->right == NULL) {
					t->right = new Node(w, d);
					return;
				} else t = t->right;
			}
		}
	}
}	//insert a word and its definition 

void Dictionary::Delete(char *w) {
	Dictionary::Node **t = Find(w, root);
	if (*t == NULL) cout << "No match!"<<endl;
	else {
		Delete(t);
	}
}	//delete a word "w" from this tree

void Dictionary::GetDef(char *w) {
	Dictionary::Node **t = Find(w, root);
	if (*t == NULL) cout << "No match!"<<endl;
	else {
		cout << "The definition of " << w << " is: ";
		for (int i = 0; i < strlen((*t)->Definition); ++i) {
			cout << (*t)->Definition[i];
		}
		cout<<endl;
	}
}	//get the definition of word "w"

void Dictionary::PrefixRetr(char *w) {
	if (!PrefixPrint(root, w)) cout << "No match!" <<endl;
} //public member function of prefix retrieving

bool Dictionary::PrefixPrint(Dictionary::Node *t, char *w) {
	if (t != NULL) {
		if (strcmp(t->Word, w) < 0) return PrefixPrint(t->right, w);
		else 
			if (strcmp(t->Word, w) == 0) {
				cout << "The definition for ";
				for (int i = 0; i < strlen(t->Word); ++i) {
					cout << t->Word[i];
				}
				cout << " is ";
				for (int i = 0; i < strlen(t->Definition); ++i) {
					cout << t->Definition[i];
				}
				cout << '.' << endl;
				PrefixPrint(t->right, w);
				return true;
			}
			else
				if (strstr(t->Word, w) != t->Word) return PrefixPrint(t->left, w);
				else {
					cout << "The definition for ";
					for (int i = 0; i < strlen(t->Word); ++i) {
						cout << t->Word[i];
					}
					cout << " is ";
					for (int i = 0; i < strlen(t->Definition); ++i) {
						cout << t->Definition[i];
					}
					cout << '.' << endl;
					PrefixPrint(t->left, w);
					PrefixPrint(t->right, w);
					return true;
				}
	} else return false;
}	//private member function of prefix retrieving