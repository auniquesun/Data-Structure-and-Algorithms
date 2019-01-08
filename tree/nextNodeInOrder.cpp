/*
problem: 给定一颗二叉树和其中一个节点，找到中序遍历该节点的下一个节点
注：这颗树的每个节点，除了左右指针，还有指向父节点的指针

idea:
1. 这个题乍看上去的做法，中序遍历，找到给定节点后的那个点就ok
	这是一种做法，但是如果树比较大的化，中序遍历一次用的时间和空间都比较大

2. 另一种方法不进行中序遍历，直接利用这棵树的结构（左右指针/父指针）搜寻
	根据中序遍历，可以总结出下面的规律
	a. 给定的node有右子树，中序遍历的下一个就是右子树最左端的节点
	b. 给定的node没有右子树，
		b1. node是其父节点的左孩子，父节点就是中序遍历node下一个节点
		b2. node是其父节点的右孩子，需要往node父节点方向逐步搜寻，
			找到了这样一个节点，它是其父节点的左孩子，返回其父节点
*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	// 在构造函数内部初始化
	// TreeNode(int value){
	// 	val = value;
	// 	left = NULL;
	// 	right = NULL;
	// 	parent = NULL;
	// }
	// 用参数列表初始化
	TreeNode(int value): val(value), left(NULL), right(NULL), parent(NULL) {}
};
class nextNodeInOrder
{
public:
	nextNodeInOrder();
	~nextNodeInOrder();
	
	TreeNode *nextNode(TreeNode *root, TreeNode *node){
		if(!root || !node)
			return NULL;

		TreeNode *current = node->right;
		TreeNode *parent = NULL;
		TreeNode *next = NULL;
		if(current){	// 如果node右子树不为空
			while(current){
				parent = current;
				current = current->left;
			}
			next = parent;
		}else{	// 如果node右子树为空
			// 有两种情况，
			// 一、node是其parent的左孩子
			parent = node->parent;
			if(parent->left == node)
				next = parent;
			// 二、node是其parent的右孩子
			else{
				current = node;
				parent = current->parent;
				while(!parent && parent->right == current){
					current = parent;
					parent = current->parent;
				}
				next = parent;
			}
		}
		return next;
	}
};