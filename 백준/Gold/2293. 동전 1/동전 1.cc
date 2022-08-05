// 동전 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> coin(100), dp(10001, 0);

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

    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int w = coin[i]; w <= K ; w++) {
            dp[w] = dp[w] + dp[w - coin[i]];
        }
    }

    cout << dp[K] << '\n';
    
    return 0;
}