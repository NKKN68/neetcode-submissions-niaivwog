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
    ListNode* middleNode(ListNode* head) {
        int k = 0;
        ListNode* p = head;
        while(p != nullptr){
            k+= 1;
            p = p->next;
        }
        ListNode* t = head;
        for (int i = 0; i < k / 2; i++ ){
            t = t->next;
        }
        return t;
    }
};