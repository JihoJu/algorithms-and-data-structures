// 랜선 자르기
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    long long k, n, low, high = INT_MIN, mid, count, max_length = 0;

    cin >> k >> n;
    
    vector<int> k_arr(k);

    for (int i = 0; i < k; i++) {
        cin >> k_arr[i];
        if (k_arr[i] > high) high = k_arr[i];
    }

    low = 1;

    while (low <= high) {
        mid = (low + high) / 2;
        count = 0;
        for (int i = 0; i < k; i++)
            count += (k_arr[i] / mid);
        if (count >= n) {
            low = mid + 1;
            if (max_length < mid) max_length = mid;
        }
        else
            high = mid - 1;
    }
    
    cout << max_length << '\n';

    return 0;
}