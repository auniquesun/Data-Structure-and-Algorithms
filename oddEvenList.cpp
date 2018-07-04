#include<iostream>

using namespace std;

// ================== problem =================
// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

// 示例 1:

// 输入: 1->2->3->4->5->NULL
// 输出: 1->3->5->2->4->NULL
// 示例 2:

// 输入: 2->1->3->5->6->4->7->NULL 
// 输出: 2->3->6->7->1->5->4->NULL
// 说明:

// 应当保持奇数节点和偶数节点的相对顺序。
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

// ================== idea =================
// 此题要求空间复杂度为 O（1），时间复杂度为 O（n），
// 如果从头到尾扫描原链表，并把结果存放于一个新建链表，时间复杂度满足，但是空间复杂度不满足要求
// 链表的一个特点就是每个节点都有一个指针，可以指向其他节点，
// ※解题的想法就是改变每个节点的指针指向，让它指到后续奇节点或偶节点，这样就不会产生额外空间开销※

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)	// 链表为空
        	return head;
        else if(!head->next)	// 链表只有一个节点
        	return head;
        else{
        	ListNode *head_odd = head, *head_even = head->next;
        	ListNode *odd = head, *even = head->next;

        	ListNode *p = NULL;	// 记录奇数位置列表最后一个节点

        	while(odd && even){
        		p = odd;	// p 值一定不为空，因为此时 odd值一定不为空
        		if(even)	//	必须再循环内部也进行判空操作
        			odd->next = even->next;
        		if(odd)
        			odd = odd->next;
        		if(odd){
				even->next = odd->next;	// 一定要有这一步，否则相当于没有改变偶数位置节点的后向指针
        			even = odd->next;
			}
        		//if(even)
        		//	even = even->next;
        	}
        	// 退出循环时，有两种可能，
        	// ①当原链表长度为偶数时，odd为空且even不为空
        	if(!odd && even)
        		p->next = head_even;
        	// ①当原链表长度为奇数时，odd不为空且指向最后一个节点，even为空
        	else{
        		p = odd;
        		p->next = head_even;
        	}

        	return head_odd;
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	ListNode *head = NULL;
	ListNode *p;	// 跟踪链表的节点
	ListNode *node;

	int i,val;

	for(i=0;i<5;i++){
		cin>>val;
		node = new ListNode(val);

		if(head == NULL){
			head = node;
			p = head;
		}
		else{
			p->next = node;
			p = p->next;
		}
	}

	Solution *solu = new Solution();
	ListNode *hh = solu->oddEvenList(head);
	ListNode *pp = hh;

	while(pp){
		cout << pp->val <<endl;
		pp = pp->next;
	}

	return 0;
}
