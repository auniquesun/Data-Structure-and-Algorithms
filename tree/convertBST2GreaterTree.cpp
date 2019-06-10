/*
problem:
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13

idea:
这道题啊，是二叉搜索树的，不管会不会做，都要想到中序遍历，
而且题目中明显提到了 ”比自身大的其他数“，很明显中序遍历就能得到 从小到大的排列 values
再对 values 进行加和操作，即把 values[i] 赋值为 += 大于它的所有数
再次中序遍历二叉树，把刚才得到的 values 赋值给各节点
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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return NULL;

        vector<int> values;

        stack<TreeNode*> st;
        TreeNode *cur = root;

        // 中序遍历二叉搜索树，结果是从小达到排的
        while(!st.empty() || cur){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            values.push_back(cur->val);
            
            cur = cur->right;
        }

        for(int i=values.size()-2; i>=0; i--){
            values[i] += values[i+1];   // 每个数，加上比它大的数
            cout << values[i] << " ";
        }
        cout << endl;

        // 重新中序遍历原来的二叉搜索数，把 values 的值赋值给各个节点
        // 由于上次 前序遍历完毕， st 一定为空， cur 一定为空
        cur = root;
        int i = 0;
        while(!st.empty() || cur){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            cur->val = values[i++];
            
            cur = cur->right;
        }

        return root;
    }
};