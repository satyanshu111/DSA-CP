# LCA of Binary Tree

**Category:** Binary Trees  
**Platform:** LeetCode  
**Link:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

## Complexity
### Approach:- 
1. Go left and if u reach either p or q no need to go deep just return that
2. If u reach null return null
3. Then if u get non null something from both left and right then that is the ans

- **Time:** O(N)  
- **Space:** O(N)(Auxilary space)
