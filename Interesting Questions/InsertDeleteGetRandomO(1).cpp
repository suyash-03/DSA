#include <iostream>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> posMap; //num, index
    vector<int> nums;
    RandomizedSet() {
        nums.clear();
        posMap.clear();
    }
    
    bool insert(int val) {
        if(posMap.find(val) != posMap.end()){
            return false;
        }
        posMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(posMap.find(val) == posMap.end()){
            return false;
        }
        int idx = posMap[val];
        int lastVal = nums.back();

        swap(nums[idx], nums.back());

        posMap[lastVal] = idx;
        nums.pop_back();
        posMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */