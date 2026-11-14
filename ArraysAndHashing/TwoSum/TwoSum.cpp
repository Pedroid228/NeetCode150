#include "Solution2.h"

int main()
{
    std::ifstream in("Tests/Test2.txt");

    if (!in)
    {
        DebugTool::OnFileOpenError();
        return 1;
    }

    std::string s;
    std::getline(in, s);
    int target = std::stoi(s);

    int num;
    std::vector<int> nums;
    while (in >> num)
    {
        nums.push_back(num);
    }

    Solution sol;
    std::cout << sol.twoSum(nums, target)[0] << " " << sol.twoSum(nums, target)[1];

    return 0;
}
