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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1 && l2){
            int n1 = l1->val;
            int n2 = l2->val;
            int ans = (n1+n2+c)%10;
            c = (n1+n2+c)/10;
            dummy->next = new ListNode(ans);
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while(l1){
            int ans = (l1->val + c)%10;
            c = (l1->val + c) /10;
            dummy->next = new ListNode(ans);
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2){
            int ans = (l2->val + c)%10;
            c = (l2->val + c) /10;
            dummy->next = new ListNode(ans);
            dummy = dummy->next;
            l2 = l2->next;
        }
        if(c){
            dummy->next = new ListNode(c);
            dummy = dummy->next;
        }

        return temp->next;
    }
};
