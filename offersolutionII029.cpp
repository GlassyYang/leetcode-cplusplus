//
// Created by zhang on 2021/9/10.
//
#include "common-header.h"

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            Node *res = new Node(insertVal);
            res->next = res;
            return res;
        }
        Node *cur = head;
        while(true) {
            if(cur->val <= insertVal) {
                if(cur->next->val >= insertVal || cur->next->val <= cur->val) {
                    break;
                }
            } else {
                if(cur->next->val < cur->val && insertVal <= cur->next->val) {
                    break;
                }
            };
            cur = cur->next;
            if(cur == head) {
                break;
            }
        }
        Node *insertNode = new Node(insertVal);
        insertNode->next = cur->next;
        cur->next = insertNode;
        return head;
    }
};