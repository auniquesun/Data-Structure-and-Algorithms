#include<iostream>

using namespace std;

/*
problem:
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

idea:
这道题其实很简单，就是想的多了，把它弄复杂了
1. 考虑链表为空的情况，
2. 若不为空，用循环同时扫描两个链表，扫描的时候比较当前节点值的大小，
    a. 把一个链表的节点插入另一个链表（选一个链表作为基准就好，我用的l1）
    b. 有一个为空时停止
3. 退出循环时，判断 基准链表是否为空，再决定是否要把另一个链表链到基准链表末尾
注细节：用 ->next / ->val 要先判断节点是否为空
*/

/*Definition for singly-linked list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL){
            return (l1 == NULL)?l2:l1;  //返回非空的链表，如果都为空，返回l2
        }

        ListNode *head1 = l1, *head2 = l2;
        ListNode *p1 = l1, *p2 = l2;

        ListNode *q1=NULL;  //记录p1的前一个节点

        while(p1 && p2){    //这个循环里，谁的值小，就把谁插到前面
            if(p1->val > p2->val){  //p2插在p1前面
                ListNode *q2 = p2->next;
                if(q1!=NULL)    //只有q1不为空时，才有q1->next, 并且把p2插入其后
                    q1->next = p2;
                p2->next = p1;
                
                q1 = p2;    //p2插在了p1前，所以用q1记录p2插入的位置，即p1前的位置
                p2 = q2;    //向前推进p2
            }
            else{
                q1 = p1;
                p1 = p1->next;
            }
        }

        if(p1 == NULL){ //如果p1为空，表明先结束，q1是它的前一个节点，p2链到q1后面
            q1->next = p2;
        }
        return (head1->val <= head2->val)?head1:head2;  //这里head1->val <= head2->val取到等号
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    ListNode *l1 = new ListNode(-2);
    l1->next = new ListNode(5);

    ListNode *l2 = new ListNode(-9);
    l2->next = new ListNode(-6);
    l2->next->next = new ListNode(-3);
    l2->next->next->next = new ListNode(-1);
    l2->next->next->next->next = new ListNode(1);
    l2->next->next->next->next->next = new ListNode(6);

    Solution *solu = new Solution();
    ListNode *res = solu->mergeTwoLists(l1, l2);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
