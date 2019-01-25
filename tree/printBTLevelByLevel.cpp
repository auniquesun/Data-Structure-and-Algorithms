#include<iostream>
#include <queue>
using namespace std;

/*
 * problem: 分层打印二叉树，显式打印出每层编号
 *
 * idea: 用队列存储节点就不用说了，
 *          a. 记录 当前层剩余节点个数，下一层节点个数
 *          b. 当前层剩余节点个数为0时，切换到下一层，
 *              下一层节点个数赋值给当前层剩余节点个数，
 *              下一层节点个数置0，重新开始计数
 * */

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

void printBTLevelByLevel(TreeNode *root){
	if(!root)
		return;

	queue<TreeNode*> q;
	q.push(root);
	int level = 1;
	int numNextLevel = 0;
	int toBePrinted = 1;

	while(!q.empty()){
		TreeNode *node = q.front();
		q.pop();
		cout << node->val << " ";

		if(node->left){
			q.push(node->left);
			numNextLevel++;
		}
		if(node->right){
			q.push(node->right);
			numNextLevel++;
		}

		toBePrinted--;
		if(toBePrinted == 0){
			cout << "第 " << level << " 层打印完毕" << endl;
			toBePrinted = numNextLevel;
			numNextLevel = 0;
			level++;
		}
	}
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	printBTLevelByLevel(root);
}
