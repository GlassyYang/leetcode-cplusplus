//
// Created by zhang on 2021/6/8.
//
#include "TreeNode.h"
#include "common-header.h"
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = minVal;
        recusive(root);
        return maxSum;
    }
private:
    int minVal = -200000000;
    int maxSum;
    int recusive(TreeNode *cur) {
        int left = minVal, right = minVal;
        if (cur->left != NULL) left = recusive(cur->left);
        if (cur->right != NULL) right = recusive(cur->right);
        int maxPath = max(left, right);
        maxSum = max(maxSum, static_cast<int>(cur->val));
        maxSum = max(maxSum, maxPath);
        maxSum = max(maxSum, maxPath + cur->val);
        maxSum = max(maxSum, left + right + cur->val);
        return max(maxPath + cur->val, cur->val);
    }
};