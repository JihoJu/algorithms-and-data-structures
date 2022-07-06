// 수 정렬하기 3
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, input;
    int arr[10001] = {0, };

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[input] += 1;
    }

    for (int i = 0; i < 10001; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++)
                cout << i << '\n';            
        }
    }

    return 0;
}