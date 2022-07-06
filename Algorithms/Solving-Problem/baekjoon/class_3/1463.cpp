// 1로 만들기
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int n, cnt = 0;
vector<int> arr;

void sol();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr.resize(n+1);
    arr[2] = 1;
    arr[3] = 1;

    sol();

    return 0;
}

void sol() {
    int m;
    
    for (int i = 4; i <= n; i++) {
        m = INT_MAX;

        if (m > arr[i-1]) m = arr[i-1];
        if (i % 3 == 0 && i % 2 == 0) {
            if (m > min(arr[i / 3], arr[i / 2]))
                m = min(arr[i / 3], arr[i / 2]);
        }
        else if (i % 3 == 0) {
            if (m > arr[i / 3])
                m = arr[i / 3];
        }
        else if (i % 2 == 0) {
            if (m > arr[i / 2])
                m = arr[i / 2];
        }
        arr[i] = m + 1;
    }

    cout << arr[n] << '\n';
}