/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* k1 = headA;
        ListNode* k2 = headB;
        while(k1 != nullptr){
            while(k2 != nullptr){
                if(k2 == k1){
                    return k1;
                } else {
                    k2 = k2->next;
                }
            }
            k2 = headB;
            k1 = k1->next;
        }
        return nullptr;
    }
};