// 요세푸스 문제 0
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, i, idx, count;

    cin >> N >> K;
    vector<pair<int, int> > arr(N + 1);
    for (i = 0; i < N; i++) {
        arr[i].first = i + 1;
        arr[i].second = 0;
    }

    i = -1;
    idx = 1;
    count = 0;
    cout << '<';
    while (true) {
        i = (i + 1) % N;
        if (arr[i].second == 1) continue;
        if (idx == K) {
            arr[i].second = 1;  // 1 이면 검사 x
            idx = 1;
            count++;
            if (count == N) {
                cout << arr[i].first << '>';
                break;
            }
            else cout << arr[i].first << ", ";
        }
        else
            idx++;
    }

    return 0;
}