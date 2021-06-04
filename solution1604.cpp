//
// Created by zhang on 2021/6/3.
//
#include "common-header.h"
class Solution {
public:
    // TODO 先吐为敬
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        const int n = keyTime.size();
        unordered_map<string, int> times;
        unordered_map<string, int> names;
        vector<string> overtimes;
        set<string> warn;
        for (int i = 0; i < n; ++i) {
            times[keyTime[i]] = i;
        }
        sort(keyTime.begin(), keyTime.end());
        int left = 0, right = left;
        while (right < n) {
            string rightBound = generateTime(keyTime[left]);
            while (right < n) {
                string &rightTime = keyTime[right];
                if (rightTime <= rightBound) {
                    int count = ++names[keyName[times[rightTime]]];
                    if (count >= 3) warn.insert(keyName[times[rightTime]]);
                } else {
                    break;
                }
                right++;
            }
            names[keyName[times[keyTime[left]]]]--;
            left++;
        }
        for(auto &name : warn) {
            overtimes.push_back(name);
        }
        return overtimes;
    }
private:
    string generateTime(string &time) {
        string hour = time.substr(0,2);
        int nHour = stoi(hour) + 1;
        string nHours = to_string(nHour);
        if (nHour < 10) {
            nHours.insert(nHours.begin(), '0');
        }
        return nHours + time.substr(2);
    }
};

int main(int argc, char **argv) {
    vector<string> keyName = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string> keyTime = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    Solution solution;
    solution.alertNames(keyName, keyTime);
}
