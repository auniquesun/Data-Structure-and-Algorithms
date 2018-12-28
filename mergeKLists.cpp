/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
problem: 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

idea:
思想其实很简单，
lists存储的是n个指针，每次找出指针指向元素的最小值，加入新链表末尾，直到找不到最小元素为止
时间复杂度为 O(L0 + L1 + ... + Ln-1)
*/

class Solution {
public:
    ListNode* minNode(vector<ListNode*>& lists){   //每次找几个列表中最小值元素的指针 
        ListNode *min = NULL;
        int index = -1;
        for(int i=0; i<lists.size(); i++)
            if(lists[i]){   //min赋值为第一个非空指针
                min = lists[i];
                index = i;
                break;
            }
        if(min){
            for(int i=0; i<lists.size(); i++){
                if(lists[i] && min->val > lists[i]->val){
                    min = lists[i];
                    index = i;
                }
            }

            lists[index] = lists[index]->next;  //最小值的指针向后移动
        }
        return min;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        else if(lists.size() == 1)
            return lists[0];
        else{
            ListNode *min = minNode(lists);
            if(min){
                ListNode *head = new ListNode(min->val);
                ListNode *p = head;

                min = minNode(lists);
                while(min){
                    ListNode *q = new ListNode(min->val);   //q是p的后一个节点
                    p->next = q;
                    p = p->next;
                    min = minNode(lists);
                }

                return head;
            }
            else
                return min;
        }
    }
};