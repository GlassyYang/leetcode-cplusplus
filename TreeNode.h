//
// Created by zhang on 2021/5/10.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#endif //LEETCODE_TREENODE_H
