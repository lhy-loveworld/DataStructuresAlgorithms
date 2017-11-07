//#380. Insert Delete GetRandom O(1)
//Medium
//Method: map and vector
//Complexity: Time O(1); Space O(N)

class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val))
            return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mp.count(val))
            return false;
        v[mp[val]] = v.back();
        mp[v.back()] = mp[val];
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};