//
// Created by zhang on 2021/5/9.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


#endif //LEETCODE_NODE_H
