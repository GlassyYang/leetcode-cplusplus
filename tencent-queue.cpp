//
// Created by zhang on 2021/9/4.
//
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>
struct LinkedListNode {
    int val;
    LinkedListNode *next;
    explicit LinkedListNode(int val) : val(val), next(NULL) {};
};

class Queue {
public:
    Queue(): head(-1), tail(&head), queueSize(0) { }
    ~Queue() { clear(); }
    void push(int);
    bool pop();
    int top();
    void clear();
    inline int size() const;
private:
    inline void increaseSize() { queueSize++; }
    inline void decreaseSize() { queueSize--; }
    LinkedListNode head;
    LinkedListNode *tail;
    int queueSize;
};

void Queue::push(int val) {
    auto *node = new LinkedListNode(val);
    tail->next = node;
    tail = node;
    increaseSize();
}

int Queue::top() {
    if(size() == 0) {
        return -1;
    }
    return head.next->val;
}

bool Queue::pop() {
    if(size() == 0) {
        return false;
    }
    LinkedListNode *deleted = head.next;
    head.next = deleted->next;
    if(tail == deleted) {
        tail = &head;
    }
    delete deleted;
    decreaseSize();
    return true;
}

int Queue::size() const {
    return queueSize;
}

void Queue::clear() {
    while (queueSize > 0) {
        pop();
    }
}

int main() {
    int t;
    using namespace std;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int q;
        cin >> q;
        Queue queue;
        string cmd;
        int operand;
        for(int j = 0; j < q; ++j) {
            cin >> cmd;
            if(cmd == "PUSH") {
                cin >> operand;
                queue.push(operand);
            } else if (cmd == "POP") {
                if(!queue.pop()) {
                    cout << -1 << endl;
                }
            } else if(cmd == "TOP") {
                cout << queue.top() << endl;
            } else if (cmd == "CLEAR") {
                queue.clear();
            } else if (cmd == "SIZE") {
                cout <<queue.size() << endl;
            }
        }
    }
}