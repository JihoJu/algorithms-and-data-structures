// 시간 관리
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> P(1000);

bool cmp(const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i].first >> P[i].second;

    sort(P.begin(), P.begin() + N, cmp);

    int time = P[0].second - P[0].first;
    
    for (int i = 1; i < N; i++) {
        if (time <= P[i].second)
            time -= P[i].first;
        else
            time = P[i].second - P[i].first;
    }

    if (time >= 0) cout << time << '\n';
    else cout << -1 << '\n';

    return 0;
}