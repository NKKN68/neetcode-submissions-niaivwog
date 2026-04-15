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
        Node* p = head;
        while(p != nullptr){
            Node* temp = new Node(p->val);
            temp->next = p->next;
            p->next = temp;
            p = p->next->next;
        }
        Node* t = head;
        while(t != nullptr){
            if(t->random != nullptr){
                t->next->random = t->random->next;
            }
            t = t->next->next;
        }
        Node* dummy = new Node(0);
        Node* dum = dummy;
        Node* run = head;
        while(run != nullptr){
            Node* tempp = run->next;
            dum->next = tempp;
            run->next = run->next->next;
            tempp->next = nullptr;
            dum = dum->next;
            run = run->next;
        }
        return dummy->next;
    }
};
