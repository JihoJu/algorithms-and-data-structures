// 영화감독 숌
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int i, n, six_rule, ten_rule, start_title = 666, title;

    cin >> n;

    i = 1;
    six_rule = 6;
    ten_rule = 10;
    title = start_title;
    while (i < n){
        for (;title  <  start_title + (1000 * six_rule); title += 1000, i++){
            if (i == n) break;
        }
        for (;(i < n) && (title < (start_title * ten_rule + ten_rule)); title++, i++){
            if (i == n) break;
        }
        six_rule  += 6 * ten_rule;
        ten_rule *= 10;
    }

    cout << title << '\n';

    return 0;
}