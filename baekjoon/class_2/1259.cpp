// 팰린드롬수
#include <iostream>

using namespace std;

string is_palindrome(int number){
    string str_num = to_string(number);
    int front_idx = 0, back_idx = str_num.size()-1;
    for (; front_idx < str_num.size() / 2; front_idx++, back_idx--){
        if (str_num[front_idx] != str_num[back_idx])
            return "no";
    }
    
    return "yes";
}

int main(){
    int num;

    while (true){
        cin >> num;
        if (num == 0) break;
        cout << is_palindrome(num) << '\n';
    }

    return 0;
}