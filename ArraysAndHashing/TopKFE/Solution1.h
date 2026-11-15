#include "../../Common.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numsF;

        for (int &num : nums)
        {
            if (numsF.find(num) != numsF.end())
            {
                numsF[num] += 1;
            }
            else
            {
                numsF[num] = 1;
            }
        }

        std::vector<std::pair<int, int>> numsFVec;

        for (const auto& [key, value] : numsF)
        {
            numsFVec.push_back({value, key});
        }

        std::sort(numsFVec.begin(), numsFVec.end(),
            [](const std::pair<int, int> &a, const std::pair<int, int> &b)
            {
                return a.first > b.first;
            });

        std::vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(numsFVec[i].second);
        }
        return result;
    }
};
