/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
problem:   环形链表的入环节点
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null

idea: 
这个题是要找到进入循环链表的节点，首先可以判断链表是否有环
快慢指针的思想
然后把满指针甩到头，快指针不动
快慢指针同时移动到相遇点，就是进入循环链表的节点
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p_fast = head;
        ListNode *p_slow = head;

        bool flag = false;
        while(p_fast && p_slow){
            if(p_fast->next)    
                p_fast = p_fast->next->next;
            if(p_slow)
                p_slow = p_slow->next;

            if(p_fast == p_slow){
                flag = true;
                break;
            }
        }

        if(flag){
            p_slow = head;
            while(p_slow != p_fast){
                p_slow = p_slow->next;
                p_fast = p_fast->next;
            }
            return p_slow;
        }
        return NULL;
    }
};