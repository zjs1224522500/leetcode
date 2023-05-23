#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int to_find_value = target - nums[i];
            auto to_find_index = hash.find(to_find_value);
            if (to_find_index != hash.end()) {
                return vector<int>{to_find_index->second, i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};