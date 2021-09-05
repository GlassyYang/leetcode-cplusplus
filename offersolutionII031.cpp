//
// Created by zhang on 2021/9/4.
//
#include <cstdlib>
#include <unordered_map>
#include <list>
namespace linked_map {
    struct BidirectionalLinkedList {
        BidirectionalLinkedList *prev;
        int key;
        int val;
        BidirectionalLinkedList *next;

        BidirectionalLinkedList(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
    };

    class LRUCache {
    public:
        LRUCache(int capacity) : remain(capacity), head(-1, -1), tail(-1, -1) {
            tail.prev = &head;
            head.next = &tail;
        }

        ~LRUCache() {
            while(head.next != &tail) {
                auto cur = head.next;
                head.next = cur->next;
                delete cur;
            }
        }

        int get(int key) {
            auto entry = map.find(key);
            if (entry == map.end()) {
                return -1;
            }
            // 将其移动到头部
            auto list = entry->second;
            insertIntoHead(list);
            return entry == map.end() ? -1 : entry->second->val;
        }

        void put(int key, int value) {
            auto entry = map.find(key);
            if (entry == map.end()) {
                if (remain) {
                    auto list = new BidirectionalLinkedList(key, value);
                    map.insert(std::make_pair(key, list));
                    list->prev = &head;
                    list->next = head.next;
                    head.next->prev = list;
                    head.next = list;
                    remain--;
                } else {
                    BidirectionalLinkedList *list = tail.prev;
                    map.erase(list->key);
                    list->key = key;
                    list->val = value;
                    map.insert(std::make_pair(key, list));
                    insertIntoHead(list);
                }
            } else {
                entry->second->val = value;
                insertIntoHead(entry->second);
            }
        }

    private:
        void insertIntoHead(BidirectionalLinkedList *list) {
            if (list->prev == &head) {
                return;
            }
            list->prev->next = list->next;
            list->next->prev = list->prev;
            list->prev = &head;
            list->next = head.next;
            head.next->prev = list;
            head.next = list;
        }

        int remain;
        std::unordered_map<int, BidirectionalLinkedList *> map;
        BidirectionalLinkedList head;
        BidirectionalLinkedList tail;
    };
}

namespace std {

    class LRUCache {
    public:
        LRUCache(int capacity) : remain(capacity){ }

        int get(int key) {
            auto entry = map.find(key);
            if(entry == map.end()) {
                return -1;
            }
            int value = entry->second->second;
            list.erase(entry->second);
            list.emplace_front(key, value);
            map[key] = list.begin();
            return value;
        }

        void put(int key, int value) {
            auto entry = map.find(key);
            if(entry == map.end()) {
                if(!remain) {
                    auto last = list.back();
                    map.erase(last.first);
                    list.pop_back();
                } else {
                    remain--;
                }
            } else {
                list.erase(entry->second);
            }
            list.emplace_front(key, value);
            map[key] = list.begin();
        }

        int remain;
        std::list<pair<int, int>> list;
        std::unordered_map<int, std::list<pair<int, int>>::iterator> map;
    };
}

int main() {
    using namespace std;
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    lruCache.get(1);
    lruCache.put(3, 3);
    lruCache.get(2);
    lruCache.put(4, 4);
}