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
        int mov = 0;
        while(head->next!= NULL){
            if(mov%2==1){
                temp = temp-> next;
            }
            head = head->next;
            if(head == temp) return true;
            mov++;
        
        }
        return false;

        
    }
};
