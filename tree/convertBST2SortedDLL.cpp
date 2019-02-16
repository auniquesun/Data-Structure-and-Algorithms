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
void convertBST2SortedDLL(TreeNode *root, TreeNode **head){	//其实就是对中序遍历作了修改
	if(root == NULL)
		return;

	static TreeNode *prev = NULL;

	convertBST2SortedDLL(root->left, head);

	if(prev == NULL)
		*head = root;
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	convertBST2SortedDLL(root->right, head);
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
    convertBST2SortedDLL(root, &head); 
  
    // Print the converted list 
    printList(head); 
  
    return 0; 
} 
