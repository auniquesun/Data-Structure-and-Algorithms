#include<iostream>
#include <vector>
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

void serialize(TreeNode *root){
	if(!root){
		cout << "^,";
		return;
	}

	cout << root->val << ",";
	serialize(root->left);
	serialize(root->right);
}

bool judge(vector<char> sequence){
	return sequence.size()>0 && sequence[0] != '^';
}

void deserialize(TreeNode **root, vector<char> sequence){
	if(judge(sequence)){
		vector<char>::iterator it = sequence.begin();
		*root = new TreeNode((*it) - '0');
		sequence.erase(it);

		deserialize(&((*root)->left), sequence);
		deserialize(&((*root)->right), sequence);
	}
}

void preOrder(TreeNode *root){
	if(!root)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);

	cout << "serialize: ";
	serialize(root);
	cout << endl;

	TreeNode *newRoot = NULL;
	char ch[] = {'1','2','4','^','^','^','3','5','^','^','6','^','^'};
	vector<char> sequence(ch, ch+sizeof(ch)/sizeof(ch[0]));
    for(int i=0; i<sequence.size(); i++)
        cout << sequence[i] << " ";
    cout << endl;

	cout << "deserialize: " << endl;
	// 注意root的传递方式
	deserialize(&newRoot, sequence);
	preOrder(newRoot);

	return 0;
}
