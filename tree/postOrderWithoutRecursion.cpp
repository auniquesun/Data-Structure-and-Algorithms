#include <iostream>
#include <unordered_map>
#include <utility>  // 包含pair

using namespace std;

/*
 * problem: 二叉树后序非递归遍历
 *
 * idea: 后序遍历，很重要的一点就是当左子树遍历完毕时，如何返回根节点, 从根节点再到右子树
 *          用一个哈希表存储每个节点的父节点
 *          时间复杂负、空间复杂度均为 O(n)
 *
 * */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postOrderWithoutRecursion(TreeNode *root){
    unordered_map<TreeNode*, TreeNode*> uo_map;
    // pair存储一对指针，第一个元素是子节点，第二个元素是父节点
    // 因为root没有父节点，所以设为空
    pair<TreeNode*, TreeNode*> chi_par(root, NULL);
    uo_map.insert(chi_par);
    while(root){
        if(root->left && uo_map.find(root->left) == uo_map.end()){
            chi_par.first = root->left;
            chi_par.second = root;
            uo_map.insert(chi_par);
            root = root->left;
        }
        else if(root->right && uo_map.find(root->right) == uo_map.end()){
            chi_par.first = root->right;
            chi_par.second = root;
            uo_map.insert(chi_par);
            root = root->right;
        }
        else{
            cout << root->val << " ";
            root = uo_map.find(root)->second;
        }
    }
}

// 用于验证 非递归方法是否正确
void postOrder(TreeNode *node){
    if (node == NULL)
        return;

    /* first recur on left child */
    postOrder(node->left);

    /* now recur on right child */
    postOrder(node->right);

    /* then print the data of node */
    cout << node->val << " ";
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(5);

	postOrder(root);
    cout << endl;

    postOrderWithoutRecursion(root);
    cout << endl;
    cout << "root value: " << root->val << endl;

	return 0;
}
