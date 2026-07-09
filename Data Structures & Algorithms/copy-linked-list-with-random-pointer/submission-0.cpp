/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map <Node* , Node*> mp;
       Node* start = head;
       while(head){
         Node* c_head = new Node(head->val);
         mp[head] = c_head; 
         head = head->next;
       }

       head = start;
       while(head){
        mp[head]->next = mp[head->next];
        mp[head]->random = mp[head->random]; 
        head = head->next;
       }
       return mp[start];
    }
};
