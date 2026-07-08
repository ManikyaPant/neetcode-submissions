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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find the sz 
        int list_size= 1;
        ListNode* duplicate = head;
        while(head->next !=NULL) {
            list_size++;
            head = head->next;
        }

        int position = list_size - n +1;
        int idx = 1;

        head = duplicate;
        ListNode* prev = NULL;       
        while(true) {
            if(idx == position){
                ListNode* temp = head; 
                head = head->next;
                if(prev){
                prev->next = head;
                }
                delete(temp);
                if(position == 1){
                    return head;
                }
                break;
            }
            prev = head;
            head = head ->next;
            idx++;
        }
        return duplicate;
    }
};
