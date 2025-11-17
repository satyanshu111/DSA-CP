# Width of Binary Tree

**Category:** Binary Trees  
**Platform:** LeetCode  
**Link:** https://leetcode.com/problems/maximum-width-of-binary-tree/

## Complexity
### Approach:- 
1. If the index of cur node is x then left childs index is 2*x, and right childs is 2*x+1(just like in segment tree)
2. To avoid overflows use normalization by doing cur = cur-mn[level]

- **Time:** O(N)  
- **Space:** O(N)(Auxilary space)
