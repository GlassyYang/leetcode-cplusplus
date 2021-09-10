//
// Created by zhang on 2021/9/8.
//

#include<iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    string line;
    unordered_map<string, bool> finished;
    unordered_map<string, vector<string>> edges;
    queue<string> que;
    int sum = 0;
    int maxTime = 0;
    string begin;
    getline(cin, begin);
    while(cin >> line) {
        int offset = line.find(',');
        string moduleName = line;
    }
}