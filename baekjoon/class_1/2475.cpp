// 검증수
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    double n;
    int test_num, sum = 0;
    
    for (int i = 0; i < 5; i++) {
        cin >> n;
        sum += pow(n, 2);
    }

    test_num = sum % 10;

    cout << test_num << endl;

    return 0;
}