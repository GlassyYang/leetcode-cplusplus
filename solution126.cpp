//
// Created by zhang on 2021/6/1.
//
#include "common-header.h"
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        const auto sSize = beginWord.length();
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        unordered_map<string, unordered_set<string>> parent;
        int step = 0;
        vector<vector<string>> res;
        if (dict.find(endWord) == dict.end()) return res;
        queue<string> que;
        que.push(beginWord);
        bool found = false;
        while (!que.empty() && !found) {
            const auto &qSize = que.size();
            step++;
            for (auto i = 0; i <qSize; i++) {
                string &cur = que.front(), curCp = cur;
                for (int j = 0; j < sSize; ++j) {
                    const char curChar = cur[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        if (k == curChar) continue;
                        cur[j] = k;
                        if (dict.find(cur) == dict.end()) continue;
                        if (!found && cur == endWord) found = true;
                        unordered_set<string> &parents = parent[cur];
                        parents.insert(curCp);
                        que.push(cur);
                    }
                    cur[j] = curChar;
                }
                dict.erase(cur);
                que.pop();
            }
        }
        deque<string> sta{endWord};
        reverse(parent, endWord, sta, res, step);
        unordered_set<string> parents = parent[endWord];
        return res;
    }
private:
    void reverse(unordered_map<string, unordered_set<string>> &parents, const string &child, deque<string> &sta, vector<vector<string>> &res, int step) {
//        cout << child << endl;
        if (step < 0) return;
        if (parents.find(child) != parents.end()) {
            unordered_set<string> &parent = parents[child];
            for (auto &p : parent) {
                sta.push_back(p);
                reverse(parents, p, sta, res, step - 1);
                sta.pop_back();
            }
        } else {
            vector<string> path;
            for (auto i = sta.rbegin(); i != sta.rend(); ++i) {
                path.push_back(*i);
            }
            res.push_back(path);
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string beginWord("hit"), endWord("cog");
    vector<string> wordList{"hot","dot","dog","lot","log", "cog"};
    vector<vector<string>> res = solution.findLadders(beginWord, endWord, wordList);
    for(auto &path : res) {
        for(auto word : path) {
            cout << word << ", ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}