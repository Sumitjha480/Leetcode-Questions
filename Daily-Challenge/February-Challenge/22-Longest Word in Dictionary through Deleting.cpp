
https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/

// Longest Word in Dictionary through Deleting


// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output: 
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.



class Solution {
public:
    bool checkSubsequence(string s, string str) {
        int i = 0, j = 0;
        if(str.length() > s.length()) 
            return false;
        while(i < s.length() && j < str.length()) 
        {
            if(s[i] == str[j]) 
                j++;
            i++;
        }
        return j == str.length();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        
        for(string& str : d) 
        {
            if(checkSubsequence(s, str) ) 
            {
                if(str.length() > ans.length() || (ans.length()==str.length() && ans>str))
                    ans = str;
            }
        }
        return ans;
    }
};
