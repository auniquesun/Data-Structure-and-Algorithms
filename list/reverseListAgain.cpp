#include<iostream>

using namespace std;

/* Definition for singly-linked list. */
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)  //空链表或者只有一个节点
            return head;

        // 这里指的都是原链表中p -> q -> r的位置关系
        ListNode *p = head; //p是开头元素
        ListNode *q = p->next;   //q是p的下一个元素
        ListNode *r = q->next; //r是q的下一个元素

        // 这一步非常重要，否则逆转之后，会陷入死循环
        head->next = NULL; //把原链表头节点的next置为空，也就是逆转之后链表的尾节点的next为空

        while(q!=NULL){ //q为空表明p没有了后继节点，即p到了尾节点
            r = q->next;  //reverse之前，q的下一个节点
            q->next = p;    //reverse -> p,q，这里p的值并没有变化
            // if(r!=NULL)
            //     r->next = q;    //reverse -> q,r，这里r的值并没有变化
            p = q;  //p向前推进
            q = r;  //q向前推进
        }

        head = p;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    Solution *solu = new Solution();
    ListNode *p = solu->reverseList(head);

    while(p){
        cout << p->val << endl;
        p=p->next;
    }


    return 0;
}
