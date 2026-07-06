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
 ListNode* solve(ListNode* parent , ListNode* node){
    if(node->next == NULL){
        node->next = parent;
        return node;
    }
    else{
        ListNode* head = solve(node , node->next);
        node->next = parent;
        return head;
    }
 }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
       return solve(NULL, head); 
    }
};
