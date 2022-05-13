// 01타일
#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> arr(N+1);

    arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= N; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
    }

    cout << arr[N] << '\n';

    return 0;
}