//
// Created by zhang on 2021/9/3.
//

#include <iostream>
using namespace std;
class Relationship {
public:
    Relationship() {
        for(int i = 0; i < NumberOfPeople; ++i) {
            sizes[i] = 1;
            parent[i] = i;
        }
    }
    int getMaxRelationNumber() const {
        int maxSize = 0;
        for(int i = 0; i < NumberOfPeople; ++i) {
            maxSize = max(maxSize, sizes[i]);
        }
        return maxSize;
    }
    int findParent(int i) {
        while(parent[i] != i) {
            int pi = parent[i];
            parent[i] = parent[pi];
            i = parent[i];
        }
        return i;
    }
    void combine(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if(x == y) {
            return;
        }
        parent[px] = py;
        sizes[py] += sizes[px];
        sizes[px] = sizes[py];
    }
private:
    static const int NumberOfPeople = 1e7 + 1;
    int sizes[NumberOfPeople];
    int parent[NumberOfPeople];
};

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        Relationship relationship;
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            relationship.combine(x, y);
        }
        cout << relationship.getMaxRelationNumber() << endl;
    }
}