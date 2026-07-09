class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev) {
        if (!head) {
            return prev;
        }

        ListNode* nextNode = head->next;

        head->next = prev;

        return reverseList(nextNode, head);
    }


    void reorderList(ListNode* head) {

        if (!head || !head->next) {
            return;
        }



        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;

            slow_prev = slow;
            slow = slow->next;
        }

        slow_prev->next = nullptr;


        ListNode* ptr1 = head;
        ListNode* ptr2 = reverseList(slow, nullptr);



        while (ptr1 && ptr2) {

            ListNode* next1 = ptr1->next;
            ListNode* next2 = ptr2->next;

            ptr1->next = ptr2;

            if (!next1) {
                break;
            }

            ptr2->next = next1;

            ptr1 = next1;
            ptr2 = next2;
        }
    }
};