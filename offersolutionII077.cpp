//
// Created by zhang on 2021/9/2.
//
#include "common-header.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head);
        return head;
    }
private:
    void quickSort(ListNode *&head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *flag = head;
        ListNode *cur = head->next;
        auto leftHead = new ListNode(-1, NULL), rightHead = new ListNode(-1, NULL);
        ListNode *left = leftHead, *right = rightHead;
        while(cur != NULL) {
            if(cur->val <= flag->val) {
                left->next = cur;
                left = left->next;
            } else {
                right->next = cur;
                right = right->next;
            }
            cur = cur->next;
        }
        left->next = NULL;
        right->next = NULL;
        quickSort(leftHead->next);
        quickSort(rightHead->next);
        left = leftHead;
        while (left->next != NULL) {
            left = left->next;
        }
        left->next = flag;
        flag->next = rightHead->next;
        head = leftHead->next;
        delete leftHead;
        delete rightHead;
    }
};

namespace mergesort {
    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            quickSort(head);
            return head;
        }
    private:
        void quickSort(ListNode *&head) {
            if(head == NULL || head->next == NULL) return;
            ListNode *flag = head;
            ListNode *cur = head->next;
            auto leftHead = new ListNode(-1, NULL), rightHead = new ListNode(-1, NULL);
            ListNode *left = leftHead, *right = rightHead;
            while(cur != NULL) {
                if(cur->val <= flag->val) {
                    left->next = cur;
                    left = left->next;
                } else {
                    right->next = cur;
                    right = right->next;
                }
                cur = cur->next;
            }
            left->next = NULL;
            right->next = NULL;
            quickSort(leftHead->next);
            quickSort(rightHead->next);
            left = leftHead;
            while (left->next != NULL) {
                left = left->next;
            }
            left->next = flag;
            flag->next = rightHead->next;
            head = leftHead->next;
            delete leftHead;
            delete rightHead;
        }
    };
}

int main() {
    ListNode *root = new ListNode(4);
    ListNode *cur = root;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(3);
    Solution solution;
    solution.sortList(root);
}