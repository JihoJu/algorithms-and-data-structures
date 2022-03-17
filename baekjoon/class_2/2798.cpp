// 블랙잭
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n, m, selected_sum, sum_temp, is_selected = 0;
vector<int> arr;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selected_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == k || j == k || i == j) continue;
                sum_temp = arr[i] + arr[j] + arr[k];
                if (sum_temp > m) continue;
                else if (sum_temp == m) {
                    selected_sum = sum_temp;
                    is_selected = 1;
                    break;
                }
                else {
                    if (sum_temp >  selected_sum) {
                        selected_sum = sum_temp;
                    }
                }
            }
            if (is_selected) break;
        }
        if (is_selected) break;
    }
    
    cout << selected_sum << '\n';

    return 0;
}