#include "../../Common.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numsF;
        for (int &num : nums)
        {
            numsF[num]++;
        }

        int maxGroupsCount = nums.size() + 1;
        std::vector<std::vector<int>> groups(maxGroupsCount);
        for (const auto& [num, freq] : numsF)
        {
            groups[freq].push_back(num);
        }

        std::vector<int> result;
        result.reserve(k);
        for (int i = maxGroupsCount - 1; i >= 0; i--)
        {
            for (int num : groups[i])
            {
                result.push_back(num);
                if (result.size() >= k)
                {
                    return result; 
                }
            } 
        }

        return {};
    }
};
