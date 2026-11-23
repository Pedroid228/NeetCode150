#include "Solution.h"

int main()
{
    std::ifstream in("Tests/Test2.txt");

    if (!in)
    {
        DebugTool::OnFileOpenError();
        return 1;
    }

    int num;
    std::vector<int> nums;
    while (in >> num)
    {
        nums.push_back(num);
    }

    Solution sol;
    std::vector<int> result = sol.productExceptSelf(nums);

    for (int product : result)
    {
        std::cout << product << " ";
    }

    return 0;
}
