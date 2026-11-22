#include "../../Common.h"

class Solution {
public:
    string encode(vector<string>& strs)
    {
        std::string encoded_str = "";
        for (int i = 0; i < strs.size(); ++i)
        {
            std::string &curr_str = strs[i];
            encoded_str += std::to_string(curr_str.length()) + "#";
            encoded_str += curr_str;
        }

        return encoded_str;
    }

    vector<string> decode(string s) 
    {
        int decoded_str_len = -1;
        int decoded_str_end_index;
        std::string curr_len_str;
        std::string decoded_str = "";
        std::vector<std::string> decoded_strs;

        for (int i = 0; i < s.length(); ++i)
        {
            char curr_sym = s[i];

            if (decoded_str_len == -1)
            {
                if (curr_sym == '#')
                {
                    decoded_str_len = std::stoi(curr_len_str);
                }
                else
                {
                    curr_len_str += curr_sym;
                }
            }
            else
            {
                decoded_str += curr_sym;
            }

            if (decoded_str_len != -1 && decoded_str.length() == decoded_str_len)
            {
                decoded_strs.push_back(decoded_str);
                decoded_str_len = -1;
                decoded_str.clear();
                curr_len_str.clear();
            }
        }

        return decoded_strs;
    }
};
