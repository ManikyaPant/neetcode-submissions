/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

public:
    bool hasCycle(ListNode* head) {
        if(head == NULL) return false;
        ListNode* temp = head;
        while(head->next!=NULL) {
            if(head->next->val == -1) {
                return true;
            }
            head->val = -1;
            head = head->next;
        }       
        return false;
    }
};
