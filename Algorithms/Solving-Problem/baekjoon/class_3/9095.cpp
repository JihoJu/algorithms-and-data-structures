// 1, 2, 3 더하기
#include <iostream>
#include <vector>

using namespace std;

int T, N, cnt = 0;
int arr[3] = {1, 2, 3};

void dfs(int n) {
    if (n == 0)
        cnt++;
    else {
        for (int i = 0; i < 3; i++) {
            if (n - arr[i] < 0)
                continue;
            dfs(n - arr[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cnt = 0;    // 경우의 수
        dfs(N);
        cout << cnt << '\n';
    }

    return 0;
}