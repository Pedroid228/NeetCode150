#include "../../Common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<string>> groups;

        for (std::string &str : strs)
        {
            std::string key = "";
            std::vector<int> counts(26, 0);

            for (int i = 0; i < str.length(); i++)
            {
                counts[(int)str[i] - (int)'a'] += 1;
            }

            for (int &count : counts)
            {
                key += std::to_string(count) + " ";
            }

            if (groups.find(key) != groups.end())
            {
                groups[key].push_back(str);
            }
            else
            {
                groups[key] = std::vector<string>{str};
            }
        }

        std::vector<std::vector<std::string>> result;

        for (auto& [key, value] : groups)
        {
            result.push_back(value);
        }

        return result;
    }
};
