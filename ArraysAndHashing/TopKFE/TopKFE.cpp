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
    int k = std::stoi(s);

    int num;
    std::vector<int> nums;
    while (in >> num)
    {
        nums.push_back(num);
    }

    Solution sol;
    std::vector<int> result = sol.topKFrequent(nums, k);
    for (int &res_num : result)
    {
        std::cout << res_num << " ";
    }

    return 0;
}
