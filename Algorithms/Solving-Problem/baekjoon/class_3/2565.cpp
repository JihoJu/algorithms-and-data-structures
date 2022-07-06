// 전깃줄
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> SET;
typedef vector<SET> ARR;
int N, line1, line2, cnt;
ARR arr;

bool cmp(SET a, SET b);
void sol();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> line1 >> line2;
        arr.push_back(make_pair(make_pair(line1, line2), 0));
    }

    cnt = 0;
    sol();

    return 0;
}

bool cmp(SET a, SET b) {
    return a.second < b.second;
}

void sol() {
    for (int i = 0; i < N - 1; i++) {
        int bx = arr[i].first.first;
        int by = arr[i].first.second;
        for (int j = i + 1; j < N; j++) {
            if (i == j) continue;
            int comp_x = arr[j].first.first;
            int comp_y = arr[j].first.second;
            if (comp_x > bx && comp_y < by) {
                arr[i].second++;
                arr[j].second++;
            }
        }
    }
    sort(arr.begin(), arr.end(), cmp);

    while (arr.back().second != 0) {
        SET s = arr.back();
        arr.pop_back();
        cnt++;
        cout << s.first.first << ' ' << s.first.second << ' ' << s.second << '\n';
        int bx = s.first.first;
        int by = s.first.second;
        for (int i = 0; i < arr.size(); i++) {
            int comp_x = arr[i].first.first;
            int comp_y = arr[i].first.second;
            if (comp_x > bx && comp_y < by || comp_x < bx && comp_y > by) {
                arr[i].second--;
            }
        }
        sort(arr.begin(), arr.end(), cmp);
    }

    cout << cnt << '\n';
}