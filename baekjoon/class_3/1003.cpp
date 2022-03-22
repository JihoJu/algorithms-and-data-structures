// 피보나치 함수
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    vector<pair<int, int> > arr(41, make_pair(-1, -1));

    cin >> T;

    arr[0] = make_pair(1, 0);
    arr[1] = make_pair(0, 1);
    for (int i = 0; i < T; i++) {
        cin >> N;
        pair<int, int> sum = make_pair(0, 0);

        if (arr[N].first != -1)
            cout << arr[N].first << ' ' << arr[N].second << '\n';
        else {
            for (int j = 2; j <= N; j++) {
                arr[j].first = arr[j - 1].first + arr[j - 2].first;
                arr[j].second = arr[j - 1].second + arr[j - 2].second;
            }
            cout << arr[N].first << ' ' << arr[N].second << '\n';
        }
    }

    return 0;
}