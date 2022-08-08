// 리모컨
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> remo(10, 1);
int N, M, start = 100, min_value = INT_MAX;

void sol(string num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    /*  ========================= 
            고장난 리모컨 입력
        ========================= */
    int broken;
    for (int i = 0; i < M; i++) {
        cin >> broken;
        remo[broken] = 0;
    }

    min_value = min(min_value, abs(start - N));

    sol("");

    cout << min_value << '\n';

    return 0;
}

void sol(string num) {
    for (int i = 0; i < 10; i++) {
        if (remo[i] == 0) continue;
        string tmp = num + to_string(i);
        int value = abs(N - stoi(tmp)) + tmp.length();
        min_value = min(min_value, value);
        if (tmp.length() < 6) {
            sol(tmp);
        }
    }
}