//
// Created by zhang on 2021/5/9.
//

#include "common-header.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
private:
    bool verifyPostorder(vector<int> &postorder, int start, int end) {
        if (start >= end - 1) return true;
        int index = start, root = postorder[end];
        while (index < end) {
            if (postorder[index] > root) break;
            index++;
        }
        for (int i = index; i < end; ++i) {
            if (postorder[i] < root) return false;
        }
        if (index == end) return verifyPostorder(postorder, start, end - 1);
        else return verifyPostorder(postorder, start, index - 1) && verifyPostorder(postorder, index, end);
    }
};
