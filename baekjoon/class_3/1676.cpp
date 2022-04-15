// 팩토리얼 0의 개수
#include <iostream>
#include <string>

using namespace std;

int N;

int sol(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int cnt = sol(N);

    cout << cnt << '\n';

    return 0;
}

int sol(int n) {
    int cnt = 0;

    for (int i = n; i >= 1; i--) {
        if (i % 125 == 0)
            cnt += 3;
        else if (i % 25 == 0)
            cnt += 2;
        else if (i % 10 == 0 || i % 5 == 0)
            cnt += 1;
    }

    return cnt;
}