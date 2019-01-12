// C++ program to print inorder traversal 
// using stack. 
#include<stack> 
#include<iostream>
using namespace std; 
  
/*
problem：二叉树的非递归遍历

idea：
对于前序/中序非递归遍历
区别仅仅在于打印数据的位置

后序遍历复杂一点，单独设一个文件讲解
*/  
/* A binary tree Node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Iterative function for inorder tree 
   traversal */
void preOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            cout << curr->data << " "; 
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */

    // 我自己的实现
    // while(curr != NULL || !s.empty()){
    //     while(curr != NULL){
    //         cout << curr->data << endl;
    //         s.push(curr);
    //         curr = curr->left;
    //     }

    //     curr = s.top();
    //     s.pop();

    //     curr = curr->right;
    // }
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7); 
  
    preOrder(root); 
    return 0; 
} 