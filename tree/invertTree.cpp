/*
problem:
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

idea:
    有一个心得，就是这种简单的递归题啊，要敢于尝试写，不能老是想，不去写
    其实是很简单的，这道题想了半天，一写就知道怎么写了
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        TreeNode * node = root->right;
        root->right = root->left;
        root->left = node;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};