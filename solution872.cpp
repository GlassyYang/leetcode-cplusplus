//
// Created by zhang on 2021/5/10.
//

#include "TreeNode.h"
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v[2];
        TreeNode* root[] = {root1, root2};
        for(int i = 0; i < 2; i++) {
            dfs(root[i], v[i]);
        }

        return v[0] == v[1];
    }

private:
    void dfs(TreeNode *root, vector<int> & v) {
        if (root->left == NULL && root->right == NULL) v.push_back(root->val);
        else {
            if (root->left != NULL) {
                dfs(root->left, v);
            }
            if (root->right != NULL) {
                dfs(root->right, v);
            }
        }
    }
};
