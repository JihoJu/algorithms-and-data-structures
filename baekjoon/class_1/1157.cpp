/* 단어 공부
시간 초과 이유
char str[100000]; 
cin.getline(str);
for (int i = 0; i < length(str); i++);

=> 이것으로 에러가 발생 -> 그냥 string type 으로 해결하자!!!
*/
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<int> alpha(26, 0);  // 알파벳 index 0 ~ 25 으로 설정
    
    cin >> str;

    char a = 'A';

    for (int i = 0; i < str.size(); i++) {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        alpha[str[i] - a]++;
    }

    int max = 0, is_same = 0;
    for (int i = 1; i < alpha.size(); i++) {
        if (alpha[max] < alpha[i]){
            max = i;
            is_same = 0;
        }
        else if (alpha[max] == alpha[i]) {
            is_same = 1;
        }
    }

    if (is_same)
        cout << "?" << endl;
    else
        printf("%c\n", a + max);

    return 0;
}