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

    /*
        {1, 2, 3} 로 3원을 만드는 경우의 수를 가정해보자
        1원으로 1원, 2원, 3원을 만들 수 있는 경우의 수는 각각 1이다.
        2원으론 1원을 절대 만들 수 없다. 2원, 3원을 만들 수 있는 경우의 수는 각각 1, 0 이다.
        3원으론 1원, 2원을 절대 만들 수 없다. 3원을 만들 수 있는 경우의 수는 1이다.
        
        1원, 2원으로 2원을 만들 수 있는 경우의 수는 1원 2개, 2원 1개로 총 2가지 이다.
        1원, 2원으로 3원을 만들 수 있는 경우의 수는 1원 3개, 2원 1개/1원 2개로 총 2가지 이다.
        1원, 2원, 3원으로 3원을 만들 수 있는 경우의 수는 1원 3개, 2원 1개/1원 2개, 3원 1개로 총 3가지 이다.

        이를 일반화 하게되면 n원에 대해 각 동전마다의 경우의 수를 추가해주면 된다. 
        일반화한 코드는 다음과 같다.
    */
   
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int w = coin[i]; w <= K ; w++) {
            dp[w] = dp[w] + dp[w - coin[i]];
        }
    }

    cout << dp[K] << '\n';
    
    return 0;
}