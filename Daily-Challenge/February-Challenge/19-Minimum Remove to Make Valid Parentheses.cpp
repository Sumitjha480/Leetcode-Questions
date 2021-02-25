https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3645/

// Minimum Remove to Make Valid Parentheses

// Given a string s of '(' , ')' and lowercase English characters. 

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
 

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.
// Example 4:

// Input: s = "(a(b(c)d)"
// Output: "a(b(c)d)"
 

// Constraints:

// 1 <= s.length <= 10^5
// s[i] is one of  '(' , ')' and lowercase English letters.



class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count=0;
        if(s=="")
            return "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                if(count>0){
                    count--;
                }
                else{
                    s[i]='#';
                }
            }
        }
        count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                count++;
            }
            else if(s[i]=='('){
                if(count>0){
                    count--;
                }
                else{
                    s[i]='#';
                }
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
                ans+=s[i];
        }
        return ans;
        
        
        // Using Vectors
        
        // if(s=="")
        //     return "";
        // vector<int>v1;
        // vector<int>v2;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         v1.push_back(i);
        //     }
        //     else if(s[i]==')')
        //     {
        //         if(v1.size()!=0)
        //         {
        //             v1.pop_back();
        //         }
        //         else
        //             v2.push_back(i);
        //     }
        // }
        // for(int i=0;i<v2.size();i++)
        //     v1.push_back(v2[i]);
        // sort(v1.begin(),v1.end());
        // int j=0;
        // string ans="";
        // if(v1.size()==0)
        //     return s;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(i!=v1[j])
        //         ans+=s[i];
        //     else if(j<v1.size()-1)
        //     {
        //         j++;
        //     }
        //     else v1[j]=-1;
        // }
        // return ans;
        
    }
};
