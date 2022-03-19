// 설탕 배달
#include <iostream>

using namespace std;

int n, number, tmp;

int get_number(){
    int n_5, is_ok = 0, count;

    n_5 = n / 5;
    while (!is_ok && n_5 >= 0) {
        tmp = n;
        count = 0;
        tmp -= (5 * n_5);
        if (tmp % 3 != 0 ) {
            n_5--;
        }
        else {
            count = (n_5 + (tmp / 3));
            is_ok = 1;
        }
    }

    if (is_ok) return count;
    
    return -1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n; 
    
    number = get_number();

    cout << number << '\n';
    
    return 0;
}