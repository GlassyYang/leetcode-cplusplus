//
// Created by zhang on 2021/9/10.
//
#include "common-header.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while(cur != nullptr) {
            if(cur->child != nullptr) {
                Node *temp = flatten(cur->child);
                cur->child = nullptr;
                Node *next = cur->next;
                cur->next = temp;
                temp->prev = cur;
                while (cur->next != nullptr) {
                    cur = cur->next;
                }
                cur->next = next;
                next->prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};