//
// Created by zhang on 2021/5/10.
//
#include "TreeNode.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

private:
    vector<TreeNode*> generate(int start, int  end) {
        vector<TreeNode*> ans;
        if (start > end) return ans;
        if (start == end) {
            TreeNode *cur = new TreeNode(start);
            ans.push_back(cur);
            return ans;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            if (left.size() == 0) {
                for (TreeNode *&r : right) {
                    TreeNode *cur = new TreeNode(i);
                    cur->right = r;
                    ans.push_back(cur);
                }
            } else if (right.size() == 0) {
                for(TreeNode *&l : left) {
                    TreeNode * cur = new TreeNode(i);
                    cur->left = l;
                    ans.push_back(cur);
                }
            } else {
                for(TreeNode *&l : left) {
                    for (TreeNode *&r : right) {
                        TreeNode *cur = new TreeNode(i);
                        cur->left = l;
                        cur->right = r;
                        ans.push_back(cur);
                    }
                }
            }
        }
        return ans;
    }
};

