#include<iostream>

using namespace std;

// ================== problem =================
// 编写一个程序，找到两个单链表相交的起始节点。

// 例如，下面的两个链表：
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// 在节点 c1 开始相交。

// 注意：
// 如果两个链表没有交点，返回 null.
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

// ================== idea =================
// 注：最后只要找到两个链表相交的 “起始节点” 即可，返回它的指针
// 这个题的关键在于时间复杂度的问题，
// 题目要求尽量满足 O(n) 的时间复杂度，我觉得说的含糊其辞
// 实际上要用 两个链表做二重循环，才能保证得到正确解
// 只扫描单链表一次，即O（n）的时间复杂度，对于某些情况不能找到解
// 例如：*headA = 【2，8，5，9，0，4，7，8，3】	*headB = 【1,1,1,1,1,1,1,1,3】

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == NULL)
    		return headA;
    	else if(headB == NULL)
    		return headB;
    	else{
        	ListNode *pa = headA, *pb = NULL;
        	while(pa){	// 只用一个循环 while(pa && pb){ if(pa->val == pb->val) return pa; pa = pa->next; pb = pb->next;} ，
        				// 这种解法是错误的
        		pb = headB;
        		while(pb){        			
	        		if(pa->val == pb->val)
	        			return pa;
        			pb = pb->next;
        		}
        		pa = pa->next;
        	}
        	return NULL;
    	}
    }
};

int main(int argc, char const *argv[])
{
	/* code */

	ListNode *headA = NULL, *headB = NULL;
	ListNode *p1, *p2;	// 分别跟踪两个链表的节点
	ListNode *node1, *node2;

	int i,val1,val2;

	for(i=0;i<3;i++){
		cin>>val1>>val2;
		node1 = new ListNode(val1);
		node2 = new ListNode(val2);

		if(headA == NULL){
			headA = node1;
			p1 = headA;
		}
		else{
			p1->next = node1;
			p1 = p1->next;
		}

		if(headB == NULL){
			headB = node2;
			p2 = headB;
		}
		else{
			p2->next = node2;
			p2 = p2->next;
		}
	}

	Solution *solu = new Solution();
	ListNode *head = solu->getIntersectionNode(headA,headB);
	ListNode *p = head;

	cout << p->val <<endl;

	return 0;
}
