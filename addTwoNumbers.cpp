#include<iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL)
    		return l2;
    	else if(l2 == NULL)
    		return l1;
    	else{	// 两个链表都不为空

    		ListNode *p1 = l1, *p2 = l2;	// 用来遍历两个链表的指针

        	int bit_sum = 0;	// 存放两数之和 % 10
        	int carry = 0;	// 存放两数之和的进位（只可能取0或1），初值为0

    		// Solution One -- 历经leetcode检验，终于通过judge了
    		// 这种解法的思想是：既然Solution Two的内存超限，那么就要设法使内存使用降下来
    		// 一种有效的方法是，计算两数之和时，"不额外生成一个新的链表"，
    		// 就用原来list1或者list2提供的内存空间，当然事先需要比较哪个链表的长度更大，选用长度大的链表

    		int len_list1=0, len_list2=0;
    		while(p1){
    			len_list1++;
    			p1=p1->next;
    		}
    		while(p2){
    			len_list2++;
    			p2=p2->next;
    		}

    		ListNode *tmp = NULL;
    		if(len_list1 < len_list2){	// 默认list1的长度大于list2：如果不满足默认条件，调换list1，list2的头指针
    			tmp = l1;
    			l1 = l2;
    			l2 = tmp;
    		}

    		ListNode *p = NULL;	// 存放指向list1链表尾部节点的指针
    		p1 = l1, p2 = l2;	// 使p1，p2重新定位到两个链表的头部
    		while(p1 && p2){

        		bit_sum = (p1->val + p2->val + carry);

        		if(bit_sum >= 10){
        			carry = 1;
        			p1->val = (bit_sum % 10);
        		}
        		else{
        			carry = 0;
        			p1->val = (bit_sum);
        		}

        		p = p1;
        		p1 = p1->next;
        		p2 = p2->next;
    		}

    		if(p1 == NULL){	// list1 为空, list2 必为空，因为 len_list1 > len_list2
        		
    			if(carry == 1){
    				ListNode *node = new ListNode(1);	// 存放指向新建节点的指针，要定义在循环内部
    				p->next = node;
    				// p = p->next;	//做不做这个操作都行
    			}
 
        	}else{	// list1 不为空, list2 必为空，因为这样才会跳出上面的 while(p1 && p2) 循环
        		while(p1){

    				bit_sum = (p1->val + carry);
    				
    				if(bit_sum >= 10){
        				carry = 1;
        				p1->val = bit_sum % 10;
    				}
        			else{
        				carry = 0;
        				p1->val = bit_sum;
        			}

        			p = p1;
        			p1 = p1->next;
    			}	// 跳出此循环，list1和list2都为空
    			if(carry == 1){
    				ListNode *node = new ListNode(1);	// 存放指向新建节点的指针，要定义在循环内部
    				p->next = node;
    				// p = p->next;	//做不做这个操作都行
    			}
        	}

        	return l1;

    		// Solution Two
    		// 这么做是一种解法，但是内存消耗很大，超出leetcode设定的内存限制，通不过judge
    		
       //  	while(p1 && p2){
       //  		ListNode *node = NULL;	// 存放指向新建节点的指针，要定义在循环内部
       //  		bit_sum = (p1->val + p2->val + carry);

       //  		if(bit_sum >= 10){
       //  			carry = 1;
       //  			node = new ListNode(bit_sum % 10);
       //  		}
       //  		else{
       //  			carry = 0;
       //  			node = new ListNode(bit_sum);
       //  		}

       //  		if(head == NULL){
       //  			head = node;
       //  			p = head;
       //  		}
       //  		else{	// 若链表不为空，把node插到链表尾部	注：因为p的存在，不用每次从head开始循环到链表尾部才能找到尾部节点
       //  			p->next = node;
       //  			p = p->next;
       //  		}

       //  		p1 = p1->next;
       //  		p2 = p2->next;
       //  	}	// 经过此循环，head不可能为NULL

       //  	if(p1 == NULL){	// list1 为空, list2 可能为空
       //  		if(p2 == NULL){
       //  			if(carry == 1){
       //  				ListNode *node = NULL;	// 存放指向新建节点的指针，要定义在循环内部
       //  				node = new ListNode(1);
       //  				p->next = node;
       //  				p = p->next;

   
       //  			}
       //  		}else{// list2不为空
       //  			while(p2){
       //  				ListNode *node = NULL;	// 存放指向新建节点的指针，要定义在循环内部

       //  				bit_sum = (p2->val + carry) % 10;
       //  				node = new ListNode(bit_sum);

       //  				if(bit_sum >= 10)
	      //   				carry = 1;
	      //   			else
	      //   				carry = 0;
	      //   			// 把节点插到末尾
	      //   			p->next = node;
       //  				p = p->next;

   
       //  			}
       //  		}
       //  	}else{	// list1 不为空, list2 必为空
       //  		while(p1){
       //  			ListNode *node = NULL;	// 存放指向新建节点的指针，要定义在循环内部

    			// 	bit_sum = (p1->val + carry) % 10;
    			// 	node = new ListNode(bit_sum);
    			// 	if(bit_sum >= 10)
       //  				carry = 1;
       //  			else
       //  				carry = 0;
       //  			// 把节点插到末尾
       //  			p->next = node;
    			// 	p = p->next;

    			// }	// 跳出此循环，list1和list2都为空
    			// if(carry == 1){
    			// 	ListNode *node = NULL;	// 存放指向新建节点的指针，要定义在循环内部

    			// 	node = new ListNode(1);
    			// 	p->next = node;
    			// 	p = p->next;

    			// }
       //  	}

       //  	return head;
    	}
    }
};

int main(int argc, char const *argv[])
{
	/* code */

	ListNode *head1 = NULL, *head2 = NULL;
	ListNode *p1, *p2;	// 分别跟踪两个链表的节点
	ListNode *node1, *node2;

	int i,val1,val2;

	for(i=0;i<3;i++){
		cin>>val1>>val2;
		node1 = new ListNode(val1);
		node2 = new ListNode(val2);

		if(head1 == NULL){
			head1 = node1;
			p1 = head1;
		}
		else{
			p1->next = node1;
			p1 = p1->next;
		}

		if(head2 == NULL){
			head2 = node2;
			p2 = head2;
		}
		else{
			p2->next = node2;
			p2 = p2->next;
		}
	}

	Solution *solu = new Solution();
	ListNode *head = solu->addTwoNumbers(head1,head2);
	ListNode *p = head;

	while(p){
		cout << p->val <<endl;
		p = p->next;
	}

	return 0;
}