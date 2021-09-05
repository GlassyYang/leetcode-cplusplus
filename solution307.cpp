//
// Created by zhang on 2021/8/29.
//

#include "common-header.h"
namespace force {
    class NumArray {
    public:

        NumArray(vector<int> &nums) : numsBuf(nums), size(nums.size()) {
            prefix.emplace_back(0);
            int sum = 0;
            for (int &num : nums) {
                sum += num;
                prefix.emplace_back(sum);
            }
        }

        void update(int index, int val) {
            int &oldVal = numsBuf[index];
            for (int i = index + 1; i <= size; ++i) {
                prefix[i] -= oldVal;
                prefix[i] += val;
            }
            numsBuf[index] = val;
        }

        int sumRange(int left, int right) {
            return prefix[right + 1] - prefix[left];
        }

    private:
        vector<int> numsBuf;
        vector<int> prefix;
        const int size;
    };
}
// 线段树求可变区间和
namespace line_tree {
    class NumArray {
    public:

        NumArray(vector<int> &nums): n(nums.size()) {
            const int size = nums.size(), treeSize = size << 1;
            line_tree = vector<int>(treeSize);
            for(int i = size; i < treeSize; ++i) {
                line_tree[i] = nums[i - size];
            }
            for(auto i = size - 1; i > 0; --i) {
                int rightChild = i << 1, leftChild = rightChild + 1;
                line_tree[i] = line_tree[leftChild] + line_tree[rightChild];
            }
        }

        void update(int index, int val) {
            index += n;
            line_tree[index] = val;
            index >>= 1;
            while(index > 0) {
                line_tree[index] = line_tree[index << 1] + line_tree[(index << 1) + 1];
                index >>= 1;
            }
        }

        int sumRange(int left, int right) {
            int sum = 0;
            left += n, right += n;
            while (left <= right) {
                if (left & 1) {
                    sum += line_tree[left];
                    left++;
                }
                if(!(right & 1)) {
                    sum += line_tree[right];
                    right--;
                }
                left >>= 1;
                right >>= 1;
            }
            return sum;
        }

    private:
        vector<int> line_tree;
        const int n;
    };
}

int main() {
    using line_tree::NumArray;
    vector<int> numbers{-1};
    NumArray test(numbers);
    cout << test.sumRange(0, 0) << endl;
    test.update(0, 1);
    cout << test.sumRange(0, 0) << endl;
}