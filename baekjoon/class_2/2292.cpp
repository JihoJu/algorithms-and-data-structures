// 벌집
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int input, order, distance = 0, n;

    cin >> input;

    n = 1;
    distance = 1;
    while(input > n) {
        n += (6 * distance);
        distance++;
    }
    
    cout << distance << '\n';

    return 0;
}