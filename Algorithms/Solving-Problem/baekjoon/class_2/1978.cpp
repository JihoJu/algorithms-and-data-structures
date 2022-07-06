// 소수 찾기
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {

    if (n == 2) return true;
    if (n == 1) return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, count;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i]))
            count++;
    }
    
    cout << count << '\n';

    return 0;
}