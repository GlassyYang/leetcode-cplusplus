//
// Created by zhang on 2021/5/17.
//
#include <cstddef>
#include "ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 首先先找到list2的末尾
        ListNode *list2Tail = list2;
        while (list2Tail->next != NULL) list2Tail = list2Tail->next;
        int count = 0;
        ListNode *cur = list1;
        while (cur->next != NULL) {
            ListNode *next  = cur->next;
            if (count == a - 1) {
                cur->next = list2;
            } else if (count == b) {
                list2Tail->next = cur->next;
            }
            count++;
            cur = next;
        }
        return list1;
    }
};

