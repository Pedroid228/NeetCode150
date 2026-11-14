#include "Solution2.h"

int main()
{
    std::ifstream in("Tests/Test1.txt");

    if (!in)
    {
        DebugTool::OnFileOpenError();
        return 1;
    }
    
    std::vector<std::string> strs;
    std::string str;
    while (in >> str)
    {
        strs.push_back(str);
    }

    Solution sol;
    vector<vector<string>> groups = sol.groupAnagrams(strs);
    for (vector<string> &group : groups)
    {
        for (std::string &word : group)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
