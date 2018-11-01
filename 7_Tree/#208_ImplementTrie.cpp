//#208. Implement Trie (Prefix Tree)
//Medium
//Method: use unordered_map to save space
//Complexity: 

class Trie {
public:
    /** Initialize your data structure here. */
    struct trieNode {
        bool isEnd;
        unordered_map<char, trieNode*> nodeMap;
        trieNode(bool b = false): isEnd(b) {}
    };
    trieNode* root;
    Trie() {
        root = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode* cur = root;
        for (char c: word) {
            if (!cur->nodeMap.count(c)) cur->nodeMap[c] = new trieNode();
            cur = cur->nodeMap[c];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode* cur = root;
        for (char c: word) {
            if (cur->nodeMap.count(c)) cur = cur->nodeMap[c];
            else return false;
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode* cur = root;
        for (char c: prefix) {
            if (cur->nodeMap.count(c)) cur = cur->nodeMap[c];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */