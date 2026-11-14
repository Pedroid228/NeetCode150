#include "../../Common.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (s.length() != t.length())
        {
            return false;
        }

        std::vector<int> lettersCount(26, 0);

        for (int i = 0; i < sLen; i++)
        {
            lettersCount[(int)s[i] - (int)'a'] += 1;
            lettersCount[(int)t[i] - (int)'a'] -= 1;
        }

        for (int &letterCount : lettersCount)
        {
            if (letterCount != 0)
            {
                return false;
            }
        }

        return true;
    }
};
