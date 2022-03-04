// 상수
#include <iostream>

using namespace std;

void to_reverse(const string str, int& to_reverse_num) {
    int radix = 100;

    for (int i = str.size() - 1; i >= 0; i--) {
        to_reverse_num += ((str[i] - '0') * radix);
        radix /= 10;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b, reverse_a = 0, reverse_b = 0;
    string a_to_str, b_to_str;
    
    cin >> a >> b;

    a_to_str = to_string(a);
    b_to_str = to_string(b);

    to_reverse(a_to_str, reverse_a);
    to_reverse(b_to_str, reverse_b);

    if (reverse_a > reverse_b) 
        cout << reverse_a << '\n';
    else 
        cout << reverse_b << '\n';

    return 0;
}