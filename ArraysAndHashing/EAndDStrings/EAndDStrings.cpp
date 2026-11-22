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

    while (std::getline(in, str))
    {
        strs.push_back(str);
    }

    Solution sol;

    std::string encoded_str = sol.encode(strs);
    std::vector decoded_strs = sol.decode(encoded_str);
    for (std::string &decoded_str : decoded_strs)
    {
        std::cout << decoded_str << " ";
    }

    return 0;
}
