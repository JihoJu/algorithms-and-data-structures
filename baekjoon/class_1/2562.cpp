// 최댓값
#include <iostream>

using namespace std;

int main() {
    int n, max = 0, max_idx;

    for (int i = 0; i < 9; i++) {
        cin >> n;
        if (max < n) {
            max = n;
            max_idx = i + 1;
        }
    }

    cout << max << endl << max_idx << endl;

    return 0;
}