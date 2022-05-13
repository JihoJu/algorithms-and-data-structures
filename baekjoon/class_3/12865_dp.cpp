//평범한 배낭 - dp (2차원 배열)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> w(N + 1), p(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> w[i] >> p[i];

    vector<vector<int> > arr(N + 1, vector<int>(K+1));

    for (int i = 0; i <= N; i++)
        arr[i][0] = 0;
    for (int i = 1; i <= K; i++)
        arr[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++)
            arr[i][j] = w[i] > j ? arr[i-1][j] : max(arr[i-1][j], arr[i-1][j-w[i]] + p[i]);
    }

    cout << arr[N][K] << '\n';
    
    return 0;
}