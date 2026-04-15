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
       ListNode* p = head;
       int length = 0;
       while(p != nullptr){
        length++;
        p = p->next;
       }
       int mid = length / 2;
       if(length % 2 == 1) mid++;
       ListNode* runprev = head;
       int dem = 1;
       while(dem < mid){
        runprev = runprev->next;
        dem ++;
       } 
       ListNode* run = runprev->next;
       runprev->next = nullptr;
       run = reverse(run);
       ListNode* merge1 = head;
       ListNode* merge2 = run;
       while(merge1 != nullptr && merge2 != nullptr){
        ListNode* temp1 = merge1->next;
        ListNode* temp2 = merge2->next;
        merge1->next = merge2;
        merge2->next = temp1;
        merge1 = temp1;
        merge2 = temp2;
       }
    }
};
