# Maximum Path Sum in Binary Tree

**Category:** Binary Trees  
**Platform:** LeetCode  
**Link:** https://leetcode.com/problems/binary-tree-maximum-path-sum/

## Intuition
At each node, we calculate:
1. The best **downward path** from the left or right child (ignore negatives using max(0, x)).
2. The best **path passing through the node** = left + right + node->val.  
   This updates the global maximum.

To the parent, we return only one side:

## Approach
- Use postorder DFS (left → right → node).
- Compute left and right contributions.
- Update global answer with "through node" path.
- Return best downward path to parent.

## Complexity
- **Time:** O(N)  
- **Space:** O(H) (recursion stack height)
