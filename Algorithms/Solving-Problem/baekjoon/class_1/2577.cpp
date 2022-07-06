// 숫자의 개수
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    vector<int> vec(10, 0);
    int n, mul = 1;
    string number;

    for (int i = 0 ; i < 3; i++) {
        cin >> n;
        mul *= n;
    }

    number = to_string(mul);

    for (int i = 0; i < number.size(); i++)
        vec[number[i] - '0'] += 1;

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;

    return 0;
}