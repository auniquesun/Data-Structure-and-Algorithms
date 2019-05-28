/*
problem:    Sort a linked list in O(n log n) time using constant space complexity.

idea:   时间复杂度倒好说，空间复杂读要求为O(1)
        不能开辟额外链表节点数个空间了

        堆排序、快排用不了，只能用快排了
        mergeSort(headRef)
            1) If the head is NULL or there is only one element in the Linked List 
                then return.
            2) Else divide the linked list into two halves.  
                splitTwoParts(head, &first, &second);
            3) Sort the two halves a and b.
                mergeSort(&first);
                mergeSort(&second);
            4) merge the sorted first and second
            and update the head pointer using headRef.
                *headRef = merge(first, second);
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *first, ListNode *second){ //first, second 分别是两个子链表的头指针
        if(first == NULL)
            return second;
        if(second == NULL)
            return first;

        ListNode *res;
        if(first->val < second->val){
            res = first;
            res->next = merge(first->next, second);
        }
        else{
            res = second;
            res->next = merge(first, second->next);
        }

        return res;
    }
    void splitTwoParts(ListNode *head, ListNode **first, ListNode **second){
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;  //
                fast = fast->next;  // 相当于slow每走1步，fast走了2步
            }
        }

        *first = head;   //找到前一半的头
        *second = slow->next;    //找到后一半的头
        slow->next = NULL;
    }
    void mergeSort(ListNode **headRef){
        ListNode *head = *headRef;
        if(head == NULL || head->next == NULL)
            return;

        ListNode *first, *second;
        splitTwoParts(head, &first, &second);

        mergeSort(&first);  // 传入的是 first 的地址，但是first 本身就是一个地址
        mergeSort(&second);

        *headRef = merge(first, second);
    }
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);   // 这个题呀，要注意各函数指针的传递
        return head;
    }
};