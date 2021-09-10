//
// Created by zhang on 2021/9/6.
//
#include "common-header.h"
class Trie;
class TrieNode{
public:
    TrieNode(bool isWord): isWord(isWord), children(alphabet, NULL) { }
private:
    static const int alphabet = 26;
    bool isWord;
    vector<TrieNode*> children;
    friend class Trie;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root('\x00') { }
    ~Trie() {
        for(TrieNode *child : root.children) {
            if(child != NULL) {
                finalize(child);
            }
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = &root;
        for(char i : word) {
            int offset = i - 'a';
            if(cur->children[offset] == NULL) {
                cur->children[offset] = new TrieNode(false);
            }
            cur = cur->children[offset];
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = findPrefix(word);
        return node != NULL && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *const leaf = findPrefix(prefix);
        return leaf != NULL;
    }
private:
    TrieNode root;
    TrieNode* findPrefix(string &word) {
        TrieNode *cur = &root;
        for(char i : word) {
            int offset = i - 'a';
            if(cur->children[offset] == NULL) {
                return NULL;
            }
            cur = cur->children[offset];
        }
        return cur;
    }
    void finalize(TrieNode *cur) {
        for(TrieNode *child : cur->children) {
            if(child != NULL) {
                finalize(child);
            }
        }
        delete cur;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("app") << endl;
    cout <<trie.search("apple") << endl;
}