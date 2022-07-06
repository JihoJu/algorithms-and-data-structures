#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, C;

bool cmp(const int a, const int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    vector<int> home(N);
    for (int i = 0; i < N; i++)
        cin >> home[i];
    sort(home.begin(), home.end(), cmp);

    int low = INT_MAX; 
    int high = home.back() - home.front();
    for (int i = 0; i < N - 1; i++) {
        low = (home[i + 1] - home[i] < low) ? home[i+1] - home[i] : low;
    }
    
    int result;
    while(low <= high) {
        int mid = (low + high) / 2;
        int cnt = 1, base = 0;
        for (int i = 1; i < home.size(); i++) {
            if (home[base] + mid <= home[i]) {
                cnt++;
                base = i;
            }
        }
        if (cnt >= C) {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << result << '\n';

    return 0;
}