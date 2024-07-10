#include <set>
#include <iostream>
#include <string>

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        
        set<char> characters;
        int start = 0, end = 0, maxLength = 0;

        while(end < s.length())
        {
            if(characters.count(s[end]) == 0)
            {               
                if(maxLength < (end - start + 1))
                    maxLength = (end - start + 1);
                
                characters.insert(s[end]);
                end++;
            }

            else
            {
                characters.erase(s[start]);
                start++;
            }
        }

        return maxLength;
    }
};