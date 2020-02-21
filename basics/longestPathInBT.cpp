/*
problem: 求二叉树中的最长路径
    
idea：1. 这个题如果需要返回最长路径长度，其实很简单，用递归求出树的高度即是最长路径的长度
      2. 如果要求组成最长路径的节点，那么其实也不复杂，
            知道树的高度后，用前序遍历树，如果栈中的节点个数等于树的高度，
            此时栈中的节点就组成了最长路径，当然最长路径可能不唯一，继续遍历还可能找到，
            这是一种可行的方案
*/

class Solution{
public:
    int longestPathInBT() {}
    vector<TreeNode*> longestPathInBT() {}
};