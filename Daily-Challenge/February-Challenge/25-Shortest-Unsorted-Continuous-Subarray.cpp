https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3652/

// Shortest Unsorted Continuous Subarray

// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Modified Approach 2
        int n = nums.size();  
        if(n<=1)
            return 0;
        int a = -1, mn  = INT_MAX, b = -1, mx  = INT_MIN,j=0;
        for(int i=n-1;i>=0;i--) {
            mn = min(mn,nums[i]);
            if(nums[i]>mn)
                a = i;
            mx = max(mx,nums[j]);
            if(nums[j]<mx)
                b = j;
            j++;
        }
        if(a == -1) {
            return 0;
        }            
        return b - a + 1;
        
        // Approach 2
        // Dekho ki last time kab aisa hua tha jab badi value pehle aa gayi thi aur choti baad me
        int n = nums.size();  
        if(n<=1)
            return 0;
        int a = -1, mn  = INT_MAX, b = -1, mx  = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            mn = min(mn,nums[i]);
            if(nums[i]>mn)
                a = i;
        }
        if(a == -1) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            mx = max(mx,nums[i]);
            if(nums[i]<mx)
                b = i;
        }             
        return b - a + 1;
        
        // Approach 1
        // Sort karke fir dekhlo ki changes kis index pe aaye
        vector<int> nums2(nums);
        sort(nums2.begin(),nums2.end());
        int a=-1,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums2[i])
            {
                a=i;
                break;
            }
                
        }
        if(a==-1)
            return 0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=nums2[i])
            {
                b=i;
                break;
            }
        }
        cout<<a<<" "<<b;
        return b-a+1;
    }
};