//
// Created by zhang on 2021/5/17.
//
# include "TreeNode.h"
#include <map>
using namespace std;
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;
        deep[root->val] = 1;
        recusive(root);
        return deep[x] == deep[y] && parents[x] != parents[y];

    }
private:
    map<int, int> parents;
    map<int, int> deep;
    void recusive(TreeNode *cur) {
        if (cur->left != NULL) {
            parents[cur->left->val] = cur->val;
            deep[cur->left->val] = deep[cur->val] + 1;
            recusive(cur->left);
        }
        if (cur->right != NULL) {
            parents[cur->right->val] = cur->val;
            deep[cur->right->val] = deep[cur->val] + 1;
            recusive(cur->right);
        }
    }
};

