// 동전 2
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, K;
vector<int> coin(101);
vector<int> dp(10001, INT_MAX);

bool cmp(const int a, const int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];

    sort(coin.begin(), coin.begin() + N, cmp);  // 동전 오름차순 정렬

    dp[0] = 0;
    for (int i = 1; i <= K; i++) {  // 1원 ~ K원 loop
        for (int j = 0; j < N; j++) {   // 동전 loop
            if ((i - coin[j]) >= 0 && dp[i - coin[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    
    if (dp[K] == INT_MAX)
        cout << -1 << '\n';
    else
        cout << dp[K] << '\n';

    return 0;
}