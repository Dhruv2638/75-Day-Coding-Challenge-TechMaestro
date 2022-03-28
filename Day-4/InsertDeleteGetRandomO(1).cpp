// name of Problem : Insert Delete GetRandom O(1)
// leetcode link of problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
// author : Dhruv Nagar

class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end()) {
            return false;
        }
        v.push_back(val);
        mpp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end()) return false;
        
        auto it = mpp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mpp[v[it->second]] = it->second;
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

