#include<iostream>
using namespace std;

/*
problem： 题目翻译过来，“把二叉排序树转换成有序的双向链表”
			DLL -> doubly linked list

idea：因为二叉排序树的中序遍历是有序的，最后双向链表也要有序，
		a. 所以肯定要用中序遍历啦
		b. 而且是递归的中序遍历
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
// 方案一，其中 静态变量 prev 有些不好理解
void convertBST2SortedDLL(TreeNode *root, TreeNode **head){	//其实就是对中序遍历作了修改
                                            // head 接收的是指针的地址，目的是拿到它修改后的值
	if(root == NULL)
		return;

	static TreeNode *prev = NULL;

	convertBST2SortedDLL(root->left, head);

	if(prev == NULL){
		*head = root;
        //cout << (*head)->val << endl;
    }
	else{
		root->left = prev;
		prev->right = root;
        //cout << root->val << endl;
        cout << prev->val << endl;
	}
	prev = root;

	convertBST2SortedDLL(root->right, head);
}
// 方案二，[ 剑指offer上的，有bug ]     不设置静态变量 prev，代码更容易理解
void BST2SortedDLL(TreeNode *root, TreeNode **lastNodeInList){
    if(root == NULL)
        return;

    TreeNode *curNodeInList = root;
    if(curNodeInList->left != NULL)
        BST2SortedDLL(curNodeInList->left, lastNodeInList);

    curNodeInList->left = *lastNodeInList; 
    if(lastNodeInList != NULL)
        (*lastNodeInList)->right = curNodeInList;
    *lastNodeInList = curNodeInList;

    if(curNodeInList->right != NULL)
        BST2SortedDLL(curNodeInList->right, lastNodeInList);
}

void printList(TreeNode *node) 
{ 
    while (node!=NULL) 
    { 
        cout << node->val << " "; 
        node = node->right; 
    } 
    cout << endl;
}

/* Driver program to test above functions*/
int main() 
{ 
    // Let us create the tree shown in above diagram 
    TreeNode *root    = new TreeNode(10); 
    root->left        = new TreeNode(8); 
    root->right       = new TreeNode(36); 
    root->left->left  = new TreeNode(5); 
    root->left->right = new TreeNode(9); 
    root->right->left = new TreeNode(15); 
  
    // Convert to DLL 
    TreeNode *head = NULL; 
    //convertBST2SortedDLL(root, &head); 
    BST2SortedDLL(root, &head);
  
    // Print the converted list 
    printList(head); 
  
    return 0; 
} 
