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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> nums;
        vector<int> nums_new;
        ListNode *p = head;

        while(p){
            nums.push_back(p->val);
            nums_new.push_back(p->val);
            p = p->next;
        }

        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            nums_new[(i+k)%n] = nums[i];
        }

        p = head;
        for(int i=0; i<nums_new.size(); i++){
            p->val = nums_new[i];
            p = p->next;
        }

        return head;
    }
};
