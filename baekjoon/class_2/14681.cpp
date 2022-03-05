// 사분면 고르기
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int x, y;

    cin >> x;
    cin >> y;

    if (x > 0 && y > 0)
        cout << "1" << '\n';
    else if (x < 0 && y > 0)
        cout << "2" << '\n';
    else if (x < 0 && y < 0)
        cout << "3" << '\n';
    else 
        cout << "4" << '\n';
        
    return 0;
}