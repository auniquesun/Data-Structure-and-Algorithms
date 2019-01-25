#include<iostream>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v){
		val = v;
		left = NULL;
		right = NULL;
	}
};

void zigzagOrderOfBT(TreeNode* root){
	if(!root)
		return;

	// 之字形遍历二叉树，要开辟两个栈
	stack<TreeNode*> st[2];

	// 设置两个变量，为了让两个栈来回调换
	int first = 0, second = 1;
	st[first].push(root);

	// 两个栈至少一个不为空
	while(!st[0].empty() || !st[1].empty()){
		if(first%2 == 0){	//根据最初始的情况推断得知
			TreeNode *node = st[first%2].top();
			st[first%2].pop();
			cout << node->val << " ";
			if(node->left)
				st[second].push(node->left);
			if(node->right)
				st[second].push(node->right);
		}
		else{
			TreeNode *node = st[first%2].top();
			st[first%2].pop();
			cout << node->val << " ";
			if(node->right)
				st[second].push(node->right);
			if(node->left)
				st[second].push(node->left);
		}
		if(st[first%2].empty()){
			second = first%2;
			first++;
		}
	}
    cout << endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	root->right->left->left = new TreeNode(12);
	root->right->left->right = new TreeNode(13);
	root->right->right->left = new TreeNode(14);
	root->right->right->right = new TreeNode(15);

	zigzagOrderOfBT(root);
	return 0;
}
