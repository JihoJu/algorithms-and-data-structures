/* 영화감독 숌
    특징을 찾고 수학적으로 접근하려고 코딩을 했다,,, 
    근데 계속 틀리다가 모든 경우의 수를 계산하려고 보니 도저히 수학적으로 접근할 수 없었다,,,
    그래서 문제 유형을 보니 "브루트포스 알고리즘" 이였다.
    후,,,
*/
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, int_title = 666, i = 1;
    string str_title = "666";

    cin >> n;
    
    while(i < n) {
        int_title++;
        if (to_string(int_title).find(str_title) != string::npos) {
            i++;
        }
    }

    cout << int_title << '\n';

    return 0;
}