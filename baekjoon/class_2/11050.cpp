// 이항 계수 1
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, tmp;

    cin >> N >> K;

    int deno = 1, numer = 1;    // deno: 분모 | numer: 분자

    if (K == 0) K = N - K;
    
    tmp = N;
    for (int i = 0; i < K; i++) {
        numer *= tmp;
        tmp--;
    }

    tmp = K;
    for (int i = 0; i < K; i++) {
        deno *= tmp;
        tmp--;
    }

    cout << (numer / deno) << '\n';

    return 0;
}