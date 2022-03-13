/* 소수 구하기

에라스토스의 체: 소수를 판별하는 알고리즘
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int m, n;   // m ~ n

    cin >> m >> n;
    
    vector<int> is_prime(n+1, 1);
    
    is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] == 0) continue;
        for (int j = 2; i * j <= n;  j++) {
            is_prime[i * j] = 0;
        }
    }

    for (int i = m; i <= n; i++) {
        if (is_prime[i] == 1)
            cout << i << '\n'; 
    }

    return 0;
}