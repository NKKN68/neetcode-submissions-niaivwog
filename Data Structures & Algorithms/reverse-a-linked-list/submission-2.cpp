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
// Khai báo lại các cấu trúc của bạn (đổi tên một chút để tránh trùng lặp với hệ thống nếu có)
struct myNode {
    int data;
    myNode *next;
    myNode *pre;
};

struct douList {
    myNode *head;
    myNode *tail;
};
class Solution {
private:
    // Giữ nguyên hàm create của bạn
    douList *create(int x) {
        douList *l = new douList;
        l->head = new myNode;
        l->head->data = x;
        l->head->next = nullptr;
        l->head->pre = nullptr;
        l->tail = l->head;
        return l;
    }

    // Giữ nguyên hàm add của bạn
    douList *add(douList *l, int x) {
        myNode *temp = new myNode;
        temp->data = x;
        temp->next = nullptr;
        l->tail->next = temp;
        temp->pre = l->tail;
        l->tail = temp;
        return l;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // Nếu danh sách rỗng, trả về rỗng
        if (head == nullptr) return nullptr;

        // 1. Thay vì dùng 'cin', ta đọc dữ liệu từ 'head' của hệ thống 
        // để tạo douList theo logic của bạn
        douList *l = create(head->val);
        ListNode* curr = head->next;
        
        while (curr != nullptr) {
            l = add(l, curr->val);
            curr = curr->next;
        }

        // 2. Thay vì dùng 'cout', ta duyệt ngược từ tail bằng con trỏ 'pre'
        // và tạo ra một danh sách ListNode mới để 'return' cho hệ thống
        myNode *p = l->tail;
        
        // Tạo node đầu tiên cho danh sách kết quả
        ListNode* newHead = new ListNode(p->data); 
        ListNode* newTail = newHead;
        p = p->pre;

        // Tiếp tục duyệt ngược douList của bạn và nối vào kết quả
        while (p != nullptr) {
            newTail->next = new ListNode(p->data);
            newTail = newTail->next;
            p = p->pre;
        }

        return newHead;
    }
};
