// 숨바꼭질
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

vector<int> arr;
int N, K;

int sol(int n, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) cout << 0 << '\n';
    else cout << sol(N, K) << '\n';

    return 0;
}

int sol(int n, int k) {
    if (k > n) {
        int size, d;
        if (n == 0 || n == 1) {
            size = 1;
            d = 1;
        }
        else {
            size = n / 2;
            d = n / 2;
        }
        while (size < k)
            size *= 2;
        arr.resize(size);

        arr[d] = 0;
        for (int i = 2 * d; i > d; i--)
            arr[i] = (i - d) > (2 * d - i + 1) ? (2 * d - i + 1) : (i - d);
        
        d *= 2;
        while (d < k) {
            for (int i = d + 2; i <= 2 * d; i += 2)
                arr[i] = arr[i / 2] + 1;
            for (int i = d + 1; i <= 2 * d; i += 2) {
                int min_value = INT_MAX;
                min_value = min(min_value, arr[i - 1] + 1);
                min_value = min(min_value, arr[i / 2] + 2);
                min_value = min(min_value, arr[i + 1] + 1);
                arr[i] = min_value;
            }
            d *= 2;
        }
        if (n == 0) return arr[k] + 1;
        else return arr[k];
    }
    else {
        return n - k;
    }
}