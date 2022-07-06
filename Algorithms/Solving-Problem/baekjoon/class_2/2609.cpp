// 최대공약수와 최소공배수
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, lcm, gcd; // lcm: 최소공배수, gcd: 최대공약수

    cin >> a >> b;

    vector<int> prime_num(b + 1, 1);    // 1 이 소수라는 것을 알려주기 위함
    gcd = 1;
    lcm = 1;

    prime_num[1] = 0;
    for (int i = 2; i <= b; i++) {
        if (prime_num[i] == 0) continue;
        for (int j = i * 2; j <= b; j+=i) {
            if (prime_num[j] == 0) continue;
            if (prime_num[j] == 1) prime_num[j] = 0;
        }
    }

    for (int i = 1; i < prime_num.size(); i++) {
        if (prime_num[i] == 0) continue;
        if (a % i == 0 && b % i == 0) {
            while (a != 0 && b != 0) {
                if (a % i != 0 || b % i != 0) break;
                gcd *= i;
                a /= i;
                b /= i;
            }
        }
    }

    lcm = gcd * a * b;

    cout << gcd << '\n' << lcm << '\n';

    return 0;
}