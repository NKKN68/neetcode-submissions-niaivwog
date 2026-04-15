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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(0); 
        ListNode* currNew = dummy;
        ListNode* currOld = head; 

        while (currOld != nullptr) {
            currNew->next = new ListNode(currOld->val);
            currNew = currNew->next;
            currOld = currOld->next;
        }   
        ListNode* copy = dummy->next; 
        delete dummy;
        ListNode* p1 = copy;
        ListNode* p2 = copy->next;
        ListNode* p3 = nullptr;
        while (p1->next != nullptr){
            p1->next = p3;
            p3 = p1;
            p1 = p2;
            p2 = p2->next;
        }
        p1->next = p3;
        ListNode* k1 = head;
        while(p1 != nullptr && head != nullptr){
            if (p1->val != head->val){
                return false;
            } else {
                p1 = p1->next;
                head = head->next;
            }
        }
        return true;
    }
};