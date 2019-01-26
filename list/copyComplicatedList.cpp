#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *sibling;
	ListNode(int v){
		val = v;
		next = NULL;
		sibling = NULL;
	}
};

void copyNext(ListNode *complicatedHead){
	if(complicatedHead){
		ListNode *node = complicatedHead;
		while(node){
			ListNode *copyNode = new ListNode(node->val);
			copyNode->next = node->next;
			node->next = copyNode;
			node = copyNode->next;
		}
	}
}

void copySibling(ListNode *complicatedHead){
	if(complicatedHead){
		ListNode *node = complicatedHead;
		ListNode *copyNode = complicatedHead->next;
		while(node){
			if(node->sibling)
				copyNode->sibling = node->sibling->next;
			if(copyNode)
				node = copyNode->next;
			if(node)
				copyNode = node->next;
		}
	}
}

ListNode *extractCopyHeadFromComplicated(ListNode *complicatedHead){
	if(complicatedHead){
		ListNode *node = complicatedHead;
		ListNode *copyHead = complicatedHead->next;
		ListNode *copyNode = complicatedHead->next;

		while(node){
			if(copyNode){
				node->next = copyNode->next;
				node = node->next;
			}
			if(node){
				copyNode->next = node->next;
				copyNode = copyNode->next;
			}
		}
		return copyHead;
	}
	return NULL;	//第一次尝试这样表示空指针
}

ListNode * copyComplicatedList(ListNode *complicatedHead){
	copyNext(complicatedHead);
	copySibling(complicatedHead);
	ListNode * copyHead = extractCopyHeadFromComplicated(complicatedHead);
	return copyHead;
}

void printList(ListNode *head){
	ListNode *node = head;
	while(node){
		cout << node->val << " ";
		if(node->next)
			cout << node->next->val << " ";
		else
			cout << node << " next为空" << " ";
		if(node->sibling)
			cout << node->sibling->val;
		else
			cout << node << " sibling为空";
        cout << endl;
		node = node->next;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	ListNode *complicatedHead = new ListNode(1);
	complicatedHead->next = new ListNode(2);
	complicatedHead->next->next = new ListNode(3);
	complicatedHead->next->next->next = new ListNode(4);
	complicatedHead->next->next->next->next = new ListNode(5);
	complicatedHead->sibling = complicatedHead->next->next;
	complicatedHead->next->sibling = complicatedHead->next->next->next->next;
	complicatedHead->next->next->next->sibling = complicatedHead->next;

	ListNode * copyHead = copyComplicatedList(complicatedHead);
	printList(copyHead);

	return 0;
}
