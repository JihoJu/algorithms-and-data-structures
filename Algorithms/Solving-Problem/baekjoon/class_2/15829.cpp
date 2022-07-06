// Hashing
#include <iostream>
#include <vector>
#include <cmath>

#define M 1234567891
#define r 31

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long L, alpha_value, result;
    string alpha;

    cin >> L;
    cin >> alpha;

    long long sum = 0, R = 1;
    for (int i = 0; i < L; i++) {
        alpha_value = (alpha[i] - 'a' + 1) % M;
        R = R % M;
        sum += (alpha_value * R) % M;
        R *= r;
    }

    result = sum % M;

    cout << result << '\n';

    return 0;
}