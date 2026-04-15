/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Định nghĩa lại cấu trúc của bạn bên trong Solution
struct myNode {
    int data;
    myNode *pre;
    myNode *next;
};

struct myDouList {
    myNode *head;
    myNode *tail;
};

class Solution {
public:
    // Giữ nguyên hàm create của bạn
    myDouList *create(int x) {
        myDouList *l = new myDouList;
        l->head = new myNode;
        l->head->data = x;
        l->head->pre = nullptr;
        l->head->next = nullptr;
        l->tail = l->head;
        return l;
    }

    // Giữ nguyên hàm addtail của bạn
    void addtail(myDouList *l, int x) {
        myNode *temp = new myNode;
        temp->data = x;
        l->tail->next = temp;
        temp->pre = l->tail;
        temp->next = nullptr;
        l->tail = temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Trường hợp đặc biệt nếu một trong hai danh sách rỗng
        if (!list1) return list2;
        if (!list2) return list1;

        // 1. Chuyển list1 sang douList 'a'
        myDouList *a = create(list1->val);
        ListNode* curr1 = list1->next;
        while (curr1) {
            addtail(a, curr1->val);
            curr1 = curr1->next;
        }

        // 2. Chuyển list2 sang douList 'b'
        myDouList *b = create(list2->val);
        ListNode* curr2 = list2->next;
        while (curr2) {
            addtail(b, curr2->val);
            curr2 = curr2->next;
        }

        // 3. Thực hiện trộn (merge) theo tư duy dùng dummy node của bạn
        myNode *p1 = a->head;
        myNode *p2 = b->head;
        myDouList *h = create(1); // Node giả

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->data < p2->data) {
                addtail(h, p1->data);
                p1 = p1->next;
            } else if (p1->data > p2->data) {
                addtail(h, p2->data);
                p2 = p2->next;
            } else { // p1->data == p2->data
                addtail(h, p1->data);
                addtail(h, p2->data);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        // Vét nốt phần còn thừa
        while (p1 != nullptr) {
            addtail(h, p1->data);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            addtail(h, p2->data);
            p2 = p2->next;
        }

        // 4. Chuyển từ douList 'h' của bạn về ListNode của hệ thống để nộp
        // Bắt đầu từ h->head->next để bỏ qua node giả (giống hàm print của bạn)
        myNode *p = h->head->next;
        if (!p) return nullptr;

        ListNode* resHead = new ListNode(p->data);
        ListNode* resCurr = resHead;
        p = p->next;

        while (p != nullptr) {
            resCurr->next = new ListNode(p->data);
            resCurr = resCurr->next;
            p = p->next;
        }

        return resHead;
    }
};