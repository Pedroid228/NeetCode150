#include "../../Common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        const int nums_size = (int)nums.size();
        int curr_prod = 1;
        std::vector<int> prefix_prod;
        std::vector<int> result;

        prefix_prod.resize(nums_size);
        result.resize(nums_size);

        for (int i = 0; i < nums_size; ++i)
        {
            prefix_prod[i] = curr_prod;
            curr_prod *= nums[i];
        }

        curr_prod = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i)
        {
            result[i] = curr_prod * prefix_prod[i];
            curr_prod *= nums[i];
        }

        return result;
    }
};
