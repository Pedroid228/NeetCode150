#include "Solution.h"

int main()
{
    std::ifstream in("Tests/Test2.txt");

    if (!in)
    {
        DebugTool::OnFileOpenError();
        return 1;
    }

    std::vector<int> nums;
    int num;

    while (in >> num)
    {
        nums.push_back(num);
    }

    Solution sol;
    std::cout << sol.hasDuplicate(nums);

    return 0;
}