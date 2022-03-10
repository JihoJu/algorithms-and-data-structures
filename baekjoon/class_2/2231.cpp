// 분해합
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, copy_n, d_sum, smallest;

    cin >> n;

    int k = n, digit = 0;
    while (k != 0) {
        k /= 10;
        digit++;
    }
    
    smallest = 0;
    copy_n = n;
    for (int i = 1; i <= 9 * digit; i++) {
        copy_n = n - i; 
        d_sum = 0;
        if (copy_n == 0) break;
        for (int j = 0; j < digit; j++) {
            d_sum += (copy_n % 10);
            copy_n /= 10;
        }
        if (d_sum == i)
            smallest = n- i;
    }

    cout << smallest << '\n';

    return 0;
}