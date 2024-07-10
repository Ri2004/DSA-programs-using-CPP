class Solution:
    def longestCommonPrefix(self, strs) -> str:
        
        strs.sort()

        str1 = strs[0]
        str2 = strs[-1]
        result = ""

        for i in range(len(str1)):
            if str1[i] != str2[i]:
                break
            
            result += str1[i]

        return result