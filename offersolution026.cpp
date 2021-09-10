//
// Created by zhang on 2021/9/9.
//

#include "common-header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr) {
                fast = fast->next;
            }
        }
        ListNode *right = slow->next, *rightReverse = right->next;
        right->next = nullptr;
        slow->next = nullptr;
        while(rightReverse != nullptr) {
            ListNode *temp = rightReverse->next;
            rightReverse->next = right;
            right = rightReverse;
            rightReverse = temp;
        }
        int count = 0;
        ListNode *cur = head->next, *left = head->next;
        while(left != nullptr || right != nullptr) {
            if(count & 1) {
                if(left != nullptr) {
                    cur->next = left;
                    cur = cur->next;
                    left = left->next;
                }
            } else {
                if(right != nullptr) {
                    cur->next = right;
                    right = right->next;
                    cur = cur->next;
                }
            }
            count++;
        }
    }
};

int main() {
    ListNode *head = new ListNode(1), *cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);
    Solution solution;
    solution.reorderList(head);
}