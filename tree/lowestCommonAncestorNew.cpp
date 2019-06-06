/*
problem:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

idea:
这道题啊，和二叉树后续遍历非递归方法有类似的思想，
    就是要用一个数据结构，记录每个节点的父节点，
    这样对于p，q，就能回溯到它们的祖先，找到最低公共祖先也就容易了

    我最初的想法也是：存储一条根节点到p，q的路径，找到这个路径上最后一个相同的节点，就是p，q的最低公共祖先
                    但是寻找路径的时候犯了一个错误，用前序遍历的方法，找到到p，q的路径，并没有记录每个节点的父亲，
                    这样前序遍历中最后一个相同的点，可能并不是p，q的祖先，它只是出现在了遍历序列的前边，
                    所以结果是错误的
*/
#include<iostream>
#include<unordered_map>
#include<utility>   // pair
#include<set>
#include<stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        stack<TreeNode*> traversal; // 用于遍历树，遍历的过程中记录每个节点的父节点
        traversal.push(root);   // 初始化，把树根放入栈
        TreeNode* cur;

        unordered_map<TreeNode*, TreeNode*> uo_map; // 关键的数据结构，用 map 存：child -> parent
        pair<TreeNode*, TreeNode*> chi_par(root, NULL); // 初始化，root没有父节点，初始化为 NULL
        uo_map.insert(chi_par); // 初始化
        
        while(!traversal.empty() && ( uo_map.find(p) == uo_map.end() || uo_map.find(q) == uo_map.end() )){  // == uo_map.end()表示p，q的父节点没存进来，也就是说p，q还没都全遍历到
            cur = traversal.top();
            traversal.pop();
            if(cur->left){
                chi_par.first = cur->left;
                chi_par.second = cur;
                uo_map.insert(chi_par);
                traversal.push(cur->left);
            }
            if(cur->right){
                chi_par.first = cur->right;
                chi_par.second = cur;
                uo_map.insert(chi_par);
                traversal.push(cur->right);
            }
        }

        set<TreeNode*> ancestors_p;
        TreeNode *node = p;
        while(node != NULL){
            ancestors_p.insert(node);
            node = uo_map.find(node)->second;   // 找到 node 的父节点, 赋值给node
        }

        node = q;
        while(node && ancestors_p.find(node) == ancestors_p.end())  // 表明 node 不在p的祖先里
            node = uo_map.find(node)->second;

        return node;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution *solu = new Solution();
    cout << "LCA of p,q :" << solu->lowestCommonAncestor(root, root->left, root->left->right->right)->val << endl;
}