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
        ListNode* prev = nullptr;
        ListNode* nex = nullptr;
        while(curr != nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        head = reverse(head);
        ListNode* p = head;
        if(n == 1){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        } else {
            int dem = 1;
            while(dem < n - 1){
                p = p->next;
                dem++;
            }
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete(temp);
        }
        return(reverse(head));
    }
};
