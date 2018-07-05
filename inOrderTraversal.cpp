#include<iostream>
#include <vector>
#include <stack>

using namespace std;

// ================== problem ==================
// 给定一个二叉树，返回它的中序 遍历。

// 示例:

// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// 输出: [1,3,2]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

// 注意：inOrderTraversal(TreeNode* root) 函数的返回值是一个向量，
// 而传入的参数是 TreeNode指针
// ※这就决定了不能用递归的方法进行中序遍历※

// =================== idea ==================
// 既然不能用递归遍历，那就用栈的方法遍历
// 1) Create an empty stack S.
// 2) Initialize current node as root
// 3) Push the current node to S and set current = current->left until current is NULL
// 4) If current is NULL and stack is not empty then 
//      a) Pop the top item from stack.
//      b) Print the popped item, set current = popped_item->right 
//      c) Go to step 3.
// 5) If current is NULL and stack is empty then we are done.
// 需要注意while循环退出条件

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inOrderTraversal(TreeNode* root) {	// 注意：这里的返回值是一个向量，而传入的参数是 TreeNode指针
    												// 这就决定了不能用递归的方法进行中序遍历
        vector<int> result;	// 建立一个空向量

        if (root != NULL)
        {
        	/* code */
        	TreeNode *cur = root;	// 用来跟踪中序遍历到的节点        	
        	TreeNode *parent = NULL;	// 用来跟踪中序遍历到的节点的父节点,，根节点没有父节点，初始情况置为NULL
        	
        	stack<TreeNode*> node_pointer_stack;
        //	node_pointer_stack.push(parent);       // 因为进入下面while循环后，用flag来判断while循环执行的条件，
        					       // 所以不需要给 node_pointer_stack 放入初始节点了

        	bool flag = true;
        	TreeNode *p = NULL;	// 记录栈顶节点

        	while(flag){
        		if(cur){
	    			parent = cur;
	    			cur = cur->left;	   			
   				node_pointer_stack.push(parent);
        		}
    			else{
    				p = node_pointer_stack.top();	// 返回值为 TreeNode* 类型
    				result.push_back(p->val);
    				cur = p->right;
    				node_pointer_stack.pop();	//	返回值为void类型，仅做弹出操作
    			}
        		
        		if(node_pointer_stack.size() == 0 && cur == NULL)	// 判断完栈的size值，必须判断cur的值
        			flag = false;
        	}
        }

        return result;
    }
};

// 递归打印原中序二叉树
void printInOrder(TreeNode *node){
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInOrder(node->left);
 
    /* then print the data of node */
    cout << node->val << " ";
 
    /* now recur on right child */
    printInOrder(node->right);
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	
//	printInOrder(root);
//	cout<<endl;

	Solution *solu = new Solution();
	vector<int> vec = solu->inOrderTraversal(root);
	for(int i=0;i < vec.size();i++)
		cout << vec[i] << " ";
	cout<<endl;

	return 0;
}
