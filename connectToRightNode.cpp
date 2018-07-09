#include<iostream>
#include <vector>
#include <queue>


using namespace std;

// ================== problem =================
// 给定一个二叉树

// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// ※填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。※

// 初始状态下，所有 next 指针都被设置为 NULL。

// 说明:

// （1）你只能使用额外常数空间。
// （2）使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
// （3）你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。	<==	这个假设是关键，利用这一条能确定扫描到了哪一层
// 示例:

// 给定完美二叉树，

//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// 调用你的函数后，该完全二叉树变为：

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

// ================== idea ==================
// 对于每层节点，next指针要指向它的右侧节点（如果有的话）
// 这个题相当于层次遍历的同时，把当前节点next指针要指向它的右侧节点
// 但是关键的一点是“要知道当前扫描到了哪一层”，否则一直指向右侧节点会引起跨层的问题
// problem 中说明（3）解决了这一问题，具体来说：
// 	对于一颗完全二叉树，第i层的节点个数不会超过 pow(2,(i-1))

struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next() {}
};

class Solution {
public:
    void connectToRightNode(TreeLinkNode *root) {		

        if(root != NULL){

	        vector<TreeLinkNode*> level;	// 存放每层的元素	     
	        
	        TreeLinkNode *cur = root;
	        queue<TreeLinkNode*> node_pointer_queue;	        

	        int cur_layer = 1;	// 当前层

	        bool flag = true;
	        while(flag){	        	

	        	int num_cur_layer_nodes = pow(2, cur_layer - 1);	// 当前层节点数，满足 num_cur_layer_nodes = pow(2, cur_layer - 1)	        

	        	if(level.size() < num_cur_layer_nodes)	// 表明 cur_layer 层节点个数未满，可以继续添加
	        		level.push_back(cur);
	        	else{	// 表明 cur_layer 层节点个数已满，需要处理该层next指针指向问题
	        		for(int i=0;i<level.size()-1;i++)
	        			level[i]->next = level[i+1];
	        		level.clear();	// 处理完该层next，清空该层节点
	        		cur_layer++;	// 层数加1

	        		level.push_back(cur);	// 把 "下一层第一个节点" 加入 层节点指针向量level
	        	}

	        	if(cur->left)
	        		node_pointer_queue.push(cur->left);
	        	if(cur->right)
	        		node_pointer_queue.push(cur->right);	      

	        	if(node_pointer_queue.empty() == true)	// 层次遍历退出的条件很简单，就是队列为空
	        		flag = false;	 
	        	else{
		        	cur = node_pointer_queue.front();
		        	node_pointer_queue.pop();	        		
	        	}      	
	        }

	        // 最后一层因为不满足 (layer_back != layer) ，
	        // 所以while循环里并没有加入这一次，要在外面加入
    		for(int i=0;i<level.size()-1;i++)
    			level[i]->next = level[i+1];
    		level.clear();
        }
		// inOrder(root);
    }

	void inOrder(TreeLinkNode *root){	// 打印中序遍历结果

		if(root == NULL)
			return;
		inOrder(root->left);
		cout<<root->val<<endl;
		inOrder(root->right);
	}

};

int main(int argc, char const *argv[])
{
	/* code */

	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);

	Solution *solu = new Solution();
	solu->connectToRightNode(root);

	return 0;
}
