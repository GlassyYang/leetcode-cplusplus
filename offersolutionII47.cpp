//
// Created by zhang on 2021/9/2.
//

#include "common-header.h"

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        pruneSubTree(root);
        return root;
    }
private:
    void pruneSubTree(TreeNode *&root) {
        if(root->left != NULL) pruneSubTree(root->left);
        if(root->right != NULL) pruneSubTree(root->right);
        if(root->left == NULL && root->right == NULL && root->val == 0) root = NULL;
    }
};
