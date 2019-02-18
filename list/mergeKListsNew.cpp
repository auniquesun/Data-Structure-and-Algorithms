#include<iostream>
#include<vector>
#include<list>
/*
 * problem: K个有序链表，合并这K个链表成1个有序链表
 *
 * idea: 1. 依次扫面K个链表，找出最小值，链接到要返回的那个链表尾部
 *          这种想法肯定能想到，也能实现
 *       2. 用递归做，代码写起来更简单，这种方法也比较好
 *          每次也是找到当前K个链表最小的节点，递归地做链接
 * */
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* mergeKListsNew(vector<ListNode*> lists, ListNode *mergeHead){
    if(lists.size() == 0)
        return NULL;
    if(lists.size() == 1)
        return lists[0];

    ListNode *node = NULL;
    int index = -1;
    for(int i=0; i<lists.size(); i++)   // node赋值为lists中第一个非空节点
        if(lists[i]){
            node = lists[i];
            index = i;
            break;
        }
    if(!node)   // 表明lists中所有链表到达尾节点, 也表明全部merge完毕
        return NULL;
    
    for(int i=0; i<lists.size(); i++)
        if(lists[i] && node && lists[i]->val < node->val){
            node = lists[i];
            index = i;
        }

    mergeHead = node;
    if(index > -1)  // 往后移动 lists[index], 更新lists，准备进入下次递归
        lists[index] = lists[index]->next;
    if(mergeHead)
        mergeHead->next = mergeKListsNew(lists, mergeHead);
    return mergeHead;
}

void printList(ListNode *node)
{
    while (node!=NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    vector<ListNode*> lists;

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(15);

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(8);
    head2->next->next->next = new ListNode(10);

    ListNode *head3 = new ListNode(3);

    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    ListNode *mergeHead = head1;
    mergeKListsNew(lists, mergeHead);
    printList(mergeHead);
}
