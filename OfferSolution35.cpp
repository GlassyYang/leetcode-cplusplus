//
// Created by zhang on 2021/5/9.
//

#include "Node.h"

#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *ans = new Node(head->val);
        map<Node*, Node*> map;
        map[head] = ans;
        Node *oldCur = head, *newCur = ans;
        while (oldCur != NULL) {
            if (oldCur->next != NULL) {
                if (map.find(oldCur->next) == map.end()) {
                    newCur->next = new Node(oldCur->next->val);
                    map.insert(make_pair(oldCur->next, newCur->next));
                } else {
                    newCur->next = map[oldCur->next];
                }
            }
            if (oldCur->random != NULL) {
                if (map.find(oldCur->random) == map.end()) {
                    newCur->random = new Node(oldCur->random->val);
                    map.insert(make_pair(oldCur->random, newCur->random));
                } else {
                    newCur->random = map[oldCur->random];
                }
            }
            oldCur = oldCur->next;
            newCur = newCur->next;
        }
        return ans;
    }
};
