#include "../../Common.h"

class Solution {
public:
    bool isAnagram(const string &s, const string &t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        std::vector counts(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            counts[(int)s[i] - (int)'a'] += 1;
            counts[(int)t[i] - (int)'a'] -= 1;
        }

        for (int &count : counts)
        {
            if (count != 0)
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> groups;

        while (strs.size() > 0)
        {
            std::vector<std::string> new_group;
            new_group.push_back(std::move(strs[0]));
            strs.erase(strs.begin());
            const std::string group_first = new_group[0];

            for (int i = 0; i < strs.size(); i++)
            {
                std::string &curr_str = strs[i];
                if (isAnagram(group_first, curr_str) == true)
                {
                    new_group.push_back(std::move(curr_str));
                    strs.erase(strs.begin() + i);
                    i--;
                }
            }

            groups.push_back(new_group);
        }

        return groups;
    }
};
