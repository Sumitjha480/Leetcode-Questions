https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/

// Valid Anagram

// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        // Solution 3
        int count[256] = { 0 };
        for (int i = 0; i<s.size(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        for (int i = 0; i < 256; i++)
            if (count[i] != 0)
                return false;

        return true;
        
        // Solution 2
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // for (int i = 0; i < s.size(); i++)
        //     if (s[i] != t[i])
        //         return false;
        // return true;
        
        
        // Solution 1
        // unordered_map<char, int> s_map, t_map;
        // for (int i=0; i < s.size(); ++i){
        //     s_map[s[i]] ++;
        //     t_map[t[i]] ++;
        // }
        // return s_map == t_map;
        
        
    }
};
