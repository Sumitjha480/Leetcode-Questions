https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/

// Binary Tree Right Side View


// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> levels;
        levels.push(root);
        while(!levels.empty())
        {
            int len=levels.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=levels.front();
                levels.pop();
                if(i==len-1)
                {
                    ans.push_back(temp->val);
                }
                if(temp->left!=NULL)
                {
                    levels.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    levels.push(temp->right);
                }
            }
            
        }
        return ans;
    }
};
