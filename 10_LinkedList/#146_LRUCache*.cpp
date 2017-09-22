//#146 LRU Cache
//Hard
//Method: The iterator will always point to the element once it is created, use it as the value in the hash map
//Complexity: Time O(1); Space O(N)

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            ls.splice(ls.begin(), ls, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->second = value;
            ls.splice(ls.begin(), ls, it->second);
        } else {
            if (ls.size() == cap) {
                int tmp = ls.back().first;
                ls.pop_back();
                mp.erase(tmp);
            }    
            ls.push_front(pair<int, int> (key, value));
            mp[key] = ls.begin();
        }
    }
private: 
    int cap;
    list<pair<int, int> > ls;
    map<int, list<pair<int, int> >::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */