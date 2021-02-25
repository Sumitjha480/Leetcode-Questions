https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/

// Container With Most Water

// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
// Example 3:

// Input: height = [4,3,2,1,4]
// Output: 16
// Example 4:

// Input: height = [1,2,1]
// Output: 2
 

// Constraints:

// n == height.length
// 2 <= n <= 3 * 104
// 0 <= height[i] <= 3 * 104



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int v=0,start=0,end=n-1;
        while(start<end)
        {
            v=max(v,(end-start)*min(height[start],height[end]));
            if(height[start]>height[end])
                end--;
            else start++;
        }
        return v;
        
        // Time Limit Exceeded
        // int n=height.size();
        // int v=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int tv=(j-i)*min(height[i],height[j]);
        //         if(tv>v)
        //             v=tv;
        //     }
        // }
        // return v;
    }
};
