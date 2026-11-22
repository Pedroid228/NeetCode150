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
        size_t i = 0;
        std::vector<std::string> decoded_strs;

        while (i < s.length())
        {
            const size_t delimiter_index = s.find('#', i);
            const int decoded_str_len = std::stoi(s.substr(i, delimiter_index - i));
            const int decoded_str_start_index = (int)delimiter_index + 1;
            const std::string decoded_str = s.substr(decoded_str_start_index, decoded_str_len);
            decoded_strs.push_back(decoded_str);

            i = decoded_str_start_index + decoded_str.length();
        }

        return decoded_strs;
    }
};
