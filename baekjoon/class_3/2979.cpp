#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

vector<int> fair(4);
vector<pair<int, int>> parking(3);

bool cmp (const pair<int, int> a, const pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min_v = INT_MAX, max_v = INT_MIN;

    cin >> fair[1] >> fair[2] >> fair[3];
    for (int i = 0; i < 3; i++) {
        cin >> parking[i].first >> parking[i].second;
        min_v = min(min_v, parking[i].first);
        max_v = max(max_v, parking[i].second);
    }
    
    int cnt, res = 0;
    for (int i = min_v; i <= max_v; i++) {
        cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (i >= parking[j].first && i < parking[j].second)
                cnt++;
        }
        res += (cnt * fair[cnt]);
    }

    cout << res << '\n';

    return 0;
}