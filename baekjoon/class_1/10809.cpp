// 알파벳 찾기
#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    vector<int> alpha(26, -1);
    string str;
    char a = 'a';

    cin >> str;

    for (int i = 0; i < str.size(); i++){
        if (alpha[str[i] - a] == -1) {
            alpha[str[i] - a] = i;
        }
    }

    for (int i = 0; i < alpha.size(); i++){
        cout << alpha[i] << ' ';
    }

    return 0;
}