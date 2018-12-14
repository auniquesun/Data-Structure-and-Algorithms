#include<algorithm> // max函数
#include<climits>
#include<iostream>

using namespace std;

/*
problem: 二叉树中的最大路径和
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

idea:
For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child

The idea is to keep trace of four paths and pick up the max one in the end. An important thing to note is, root of every subtree need to return maximum path sum such that at most one child of root is involved. This is needed for parent function call. In below code, this sum is stored in ‘max_single’ and returned by the recursive function.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // This function returns overall maximum path sum in 'res' 
    // And returns max path sum going through root. 
    // 这个递归函数有个很关键的思想，就是每次返回值是 max_single，
    // 也就是说 看根节点需不需要加上 最大子树pathsum值，而不是返回 res
    int findMaxUtil(TreeNode* root, int &res) 
    { 
        if(root == NULL)
            return 0;

        //递归，分别找到左右子树中最大路径和
        int left = findMaxUtil(root->left, res);
        int right = findMaxUtil(root->right, res);

        // 寻找 maxPathSum，分情况两两比较，循序渐进的思想
        int max_child = max(left, right);   //从左右子树里找到路径和最大值
        int max_single = max(root->val, max_child + root->val); //判断max_child加上根节点值是不是更大
        int max_top = max(max_single, left + right + root->val);    //判断左、右、根加起来有没有max_single大

        res = max(res, max_top);    //最大的路径总是记录在 res 里
        return max_single;  //这里返回 max_single, 是出于 findMaxUtil 递归的要求
        
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;

        // Initialize result 
        int res = INT_MIN; 
    
        // Compute and return result 
        findMaxUtil(root, res); 
        return res; 
    }
};

int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(-11);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution *solu = new Solution();
    int res = solu->maxPathSum(root);
    cout << "res" << ": " << res << endl;
}