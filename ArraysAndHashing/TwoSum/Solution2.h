#include "../../Common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            auto prev_num_index = seen.find(diff);
            if (prev_num_index != seen.end())
            {
                return {prev_num_index->second, i};
            }
            else
            {
                seen[nums[i]] = i;
            }
        }
        
        return {};
    }
};
