https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3658/

// Set Mismatch

// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1]
// Output: [1,2]
 

// Constraints:

// 2 <= nums.length <= 104
// 1 <= nums[i] <= 104


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> check;
        vector<int> ans;
        int n=nums.size(),sum = accumulate(nums.begin(), nums.end(), 0);
        int sumx = n*(n+1)/2;
        for(int i=0;i<nums.size();i++)
        {
            if(check[nums[i]]!=0)
                ans.push_back(nums[i]);
            else
                check[nums[i]]=1;          
        }
        ans.push_back(sumx-sum+ans[0]);
        return ans;
        // Or we can run a loop on map to check which number has 0 count from 1 to 0 
        // to find the missing element
    }
};