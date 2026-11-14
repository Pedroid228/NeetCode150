#include "Solution.h"

int main()
{
    std::ifstream in("Tests/Test2.txt");

    if (!in)
    {
        DebugTool::OnFileOpenError();
        return 1;
    }
    
    std::string t, s;

    std::getline(in, t);
    std::getline(in, s);

    Solution sol;

    std::cout << sol.isAnagram(t, s);

    return 0;
}
