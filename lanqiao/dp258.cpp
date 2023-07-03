//
// Created by Administrator on 2023/3/22.
//

#include <iostream>
#include <vector>
using namespace std;

int m;
int n;
vector<int> tracked;
vector<bool> used;
vector<vector<int>> result;
void backtrack(int previous) {
    if (tracked.size() == m) {
        result.push_back(tracked);
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (used[i]) {
            continue;
        }
        int sub = abs(previous - i);
        if ( previous == -1 || sub == n || sub == 1 || sub == n-1 || sub == n+1) {
            continue;
        }
        tracked.push_back(i);
        used[i] = true;
        backtrack(i);
        tracked.pop_back();
        used[i] = false;
    }
}

int main()
{
    n = 2 ;
    m = n * 2;
    used = vector<bool>(m,false);
    backtrack(-1); // 初始值
    cout << result.size() << endl;
    for(vector<int> a : result) {
        for(int i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}