#include <iostream>
#include <cmath>
using namespace std;

/*
problem: 求两个链表的相交节点（如果有的话，没有返回NULL）

idea：	1. 时间复杂度为O(n*m)的解法就不赘述了
		2. 如何在O(n+m)的复杂度下解决此问题
			a. 如果两链表有相交节点的情况下，
				无非在头节点相交/尾节点相交/中间节点相交
			b. 链表题常用快慢指针的方法
			c. 基于以上两点认识，可以这样做：
				c1. 分别求出两链表长度，求出长度差 diff
				c2. 让长的链表先走diff步，然后同时走，直到两链表指向同一节点
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v){
		val = v;
		next = NULL;
	}
};

void printList(ListNode *head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

int length(ListNode *head){
    ListNode *p = head;
	int length = 0;
    // 非常低级的错误，要用while，而不是if
	while(p){
		length++;
		p = p->next;
	}
	return length;
}

ListNode * intersectionNode(ListNode *head1, ListNode *head2){
	int length1 = length(head1);
    cout << "length1: " << length1 << endl;
	int length2 = length(head2);
    cout << "length2: " << length2 << endl;

	// 默认list1比list2长
	ListNode *pLong = head1;
	ListNode *pShort = head2;
	int diff = length1 - length2;

	if(diff < 0){
		pLong = head2;
		pShort = head1;
	}

	int count = 0;
	while(count < abs(diff) && pLong){
		count++;
		pLong = pLong->next;
	}

	while(pShort && pLong && pShort != pLong){
		pShort = pShort->next;
		pLong = pLong->next;
	}

	return pLong;
}

int main(){
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(6);
	head1->next->next->next->next = new ListNode(7);
	ListNode *head2 = new ListNode(4);
	head2->next = new ListNode(5);
	head2->next->next = head1->next->next->next;
	head2->next->next->next = head1->next->next->next->next;

    cout << "list1: ";
    printList(head1);
    cout << endl;
    cout << "list2: ";
    printList(head2);
    cout << endl;

    ListNode *node = intersectionNode(head1, head2);
	cout << "intersection node is: " << node << ", its value is: " << node->val << endl;
}
