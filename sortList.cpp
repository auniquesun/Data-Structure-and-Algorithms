/*
problem: 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

idea:
想法很简单，就是把原链表节点中的值取出来，存放到一个数组
1. 对数组排序
2. 依次覆盖掉原链表中的值
*/

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode * p = head;

        vector<int> nums;   //存放链表中的数值

        while(p){
            nums.push_back(p->val);
            p = p->next;
        }

        sort(nums.begin(), nums.end()); //对数值排序，调用了内置库
        p = head;   //p重新定位到头部

        for(int i=0;i<nums.size() && p!=NULL;i++){
            p->val = nums[i];
            p = p->next;
        }

        return head;
    }
};