# Maximum Path Sum in Binary Tree

**Category:** Binary Trees  
**Platform:** LeetCode  
**Link:** https://leetcode.com/problems/binary-tree-maximum-path-sum/

## Intuition
At each node, we calculate two things:
1. best which it can pass over to its parent
2. update ans assuming max sum path passes through it.

## Approach
- Compute left and right contributions.
- Update global answer with "through node" path.
- Return best downward path to parent.

## Complexity
- **Time:** O(N)  
- **Space:** O(H) (recursion stack height)
