https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/

# Binary Tree Right Side View


# Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

# Example:

# Input: [1,2,3,null,5,null,4]
# Output: [1, 3, 4]
# Explanation:

#    1            <---
#  /   \
# 2     3         <---
#  \     \
#   5     4       <---


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ans=[]
        if not root:
            return ans
        level=[root]
        while level:
            size=len(level)
            for i in range(size):
                if i==size-1:
                    ans.append(level[0].val)
                if level[0].left:
                    level.append(level[0].left)
                if level[0].right:
                    level.append(level[0].right)
                level.pop(0)
        return ans
