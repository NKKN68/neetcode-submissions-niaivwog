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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* nex = nullptr;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
       ListNode* mouse1 = head;
       ListNode* mouse2 = head;
       while(mouse2->next != nullptr && mouse2->next->next != nullptr){
        mouse1 = mouse1->next;
        mouse2 = mouse2->next->next;
       }
       ListNode* mouse2n = mouse1->next;
       mouse1->next = nullptr;
       mouse2n = reverse(mouse2n);
       ListNode* merge1 = head;
       ListNode* merge2 = mouse2n;
       while(merge2 != nullptr){
        ListNode* temp1 = merge1->next;
        ListNode* temp2 = merge2->next;
        merge1->next = merge2;
        merge2->next = temp1;
        merge1 = temp1;
        merge2 = temp2;
       }
    }
};
