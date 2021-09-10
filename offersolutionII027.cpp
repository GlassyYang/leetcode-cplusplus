//
// Created by zhang on 2021/9/10.
//
#include "common-header.h"
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode *cur = head;
        while(cur != nullptr) {
            cur = cur->next;
            length++;
        }
        cur = head;
        for(int i = 1; i < (length + 1) >> 1; ++i) {
            cur = cur->next;
        }
        ListNode *reverse = cur->next;
        cur->next = nullptr;
        cur = reverse->next;
        reverse->next = nullptr;
        while(cur != nullptr) {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = reverse;
            reverse = temp;
        }
        cur = head;
        while(reverse != nullptr && cur != nullptr) {
            if(reverse->val != cur->val) {
                return false;
            }
            reverse = reverse->next;
            cur = cur->next;
        }
        return true;
    }
};

int main() {
    ListNode *head = new ListNode(1), *cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    Solution solution;
    solution.isPalindrome(head);
}