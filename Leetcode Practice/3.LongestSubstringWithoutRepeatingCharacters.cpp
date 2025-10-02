#include <iostream>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s == "") return 0;
        string result = "";
        int index = 0;
        int max = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if((result != ""))
            {
                for(int j = 0; j < result.size(); j++)
                {
                    if(result[j] == s[i])
                    {
                        if(max < result.size()) max = result.size();
                        index = 0;
                        result = "";
                        break;
                    }
                }
            }
            result += s[i];
            index++;
        }
        return max;
    }
};