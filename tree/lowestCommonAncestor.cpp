/* Definition for a binary tree node. */
#include<vector>
#include<iostream>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //判断节点p是否在以root为根的树中，如果在，记录该路径并且返回true
    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* p){
        if(root == NULL)
            return false;

        path.push_back(root);

        //如果root的值与p的值相同，说明它们是同一个节点
        if(root->val == p->val)
            return true;

        //在root->left, root->right为根的树中查找
        if((root->left && findPath(root->left, path, p)) || (root->right && findPath(root->right, path, p)))
            return true;
        
        //p即不等于root，也不在root的左右子树，弹出root，返回false
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;   //记录从root到p的路径
        vector<TreeNode*> path_q;   //记录从root到q的路径

        // cout << "开始迭代" << endl;
        //在root为根的树中没有找到p，q
        if(!findPath(root, path_p, p) || !findPath(root, path_q, q))
            return NULL;

        cout << "path_p: " << path_p.size() << endl;
        for(int j=0; j<path_p.size(); j++)
            cout << path_p[j]->val << endl;

        cout << "path_q: " << path_q.size() << endl;
        for(int j=0; j<path_q.size(); j++)
            cout << path_q[j]->val << endl;

        int i;
        // 找到第一个数值不相等节点
        for(i=0;i<path_p.size() && i<path_q.size();i++){
            if(path_p[i]->val != path_q[i]->val){
                break;
            }
        }
        cout << "i: " << i << endl;
        return path_p[i-1];
    }
};

int main(){
    TreeNode *root = new TreeNode(-1); 
    root->left = new TreeNode(0); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(-2); 
    root->left->right = new TreeNode(4); 
    root->left->left->left = new TreeNode(8); 

    Solution *solu = new Solution();
    cout << "LCA(4, 5) = " << solu->lowestCommonAncestor(root, root->left->left->left, root)->val; 
    // cout << "nLCA(4, 6) = " << solu->lowestCommonAncestor(root, root->left->left, root->right->left)->val; 
    // cout << "nLCA(3, 4) = " << solu->lowestCommonAncestor(root, root->right, root->left->left)->val; 
    // cout << "nLCA(2, 4) = " << solu->lowestCommonAncestor(root, root->left, root->left->left)->val; 
}