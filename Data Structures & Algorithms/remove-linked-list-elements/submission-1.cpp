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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } 
        if(head == nullptr){
            return nullptr;
        }
        ListNode* p2 = head;
        while(p2->next != nullptr){
            if (p2->next->val == val){
                ListNode* temp = p2->next;
                p2->next = p2->next->next;
                delete temp;
            } else {
                p2 = p2->next;
            }
        }
        return head;
    }
};