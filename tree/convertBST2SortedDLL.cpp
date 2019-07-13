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
// 方案一，其中 静态变量 prev 有些不好理解，我的解决方案不用静态变量了，用指针引用代替
void convertBST2SortedDLL(TreeNode *root, TreeNode **head, TreeNode *&prev){	//其实就是对中序遍历作了修改
                                            // head 接收的是指针的地址，目的是拿到它修改后的值
	if(root == NULL)
		return;

    // 原来 prev 是设置成静态变量的
	//static TreeNode *prev = NULL;

	convertBST2SortedDLL(root->left, head, prev);

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

	convertBST2SortedDLL(root->right, head, prev);
}

void printList(TreeNode *node)
{
    TreeNode *reverse_node = NULL;
    // 从左到右打印
    while (node!=NULL)
    {
        cout << node->val << " ";
        reverse_node = node;
        node = node->right;
    }
    cout << endl;
    // 从右到左打印
    while (reverse_node!=NULL)
    {
        cout << reverse_node->val << " ";
        reverse_node = reverse_node->left;
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
    TreeNode *prev = NULL;
    convertBST2SortedDLL(root, &head, prev);

    // Print the converted list
    printList(head);

    return 0;
}
