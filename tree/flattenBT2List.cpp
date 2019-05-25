/*
problem: 给定一颗二叉树，按照前序遍历的顺序，把它转换成一个链表，要求in-place实现
            注：原 leetcode 表述不清楚
examples:
    Input : 
            1
            /   \
        2     5
        / \     \
        3   4     6

    Output :
        1
        \
        2
        \
            3
            \
            4
            \
                5
                \
                6

    Input :
            1
        / \
        3   4
            /
            2
            \
            5
    Output :
        1
        \
        3
            \
            4
            \
            2
                \ 
                5

idea：  1. 由于in-place 的要求，不能开辟n个新节点，把原来的二叉树按照前序遍历连接
        2. 寻求其他方法，递归是容易想到的，但是实现细节不好一下想出来
            a. 判断特殊情况，作为递归退出的条件，这里就是空树或者只有根节点的树
            b. 若左子树不为空，递归flatten左子树；
                保存右子树指针 root->right 为tmp; 把左子树 root->left 赋值给 root->right; 
                这样树的结构就改变了，成了一颗新的树，找到新树右子树最右边节点 node，
                把 tmp 接到 node->right
            c. 递归flatten右子树
            
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
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return;

        if(root->left){
            flatten(root->left);

            // 走到这里，root必不为空，所以root->left,root->right都可用
            TreeNode *tmp = root->right;    // 记录root->right
            root->right = root->left;   // root->left接到root->right
            root->left = NULL;  // root->left 值为空

            TreeNode *node = root;
            while(node->right)  // 找到以root为根，最有侧的节点
                node = node->right;

            node->right = tmp;  // 把原始的右子树接到 新树最右侧的右结点
        }
        flatten(root->right);
    }
};