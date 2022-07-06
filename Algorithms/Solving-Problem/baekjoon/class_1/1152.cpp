// 단어의 개수
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string str;
    int word_num = 0, is_word = 0;

    getline(cin, str);

    if (str.empty()) {  // 문자열이 아예 공백만 들어올 경우
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < str.size(); i++) {
        if (!isspace(str.at(i))){
            is_word = 1;
            if (i == str.size() - 1)
                word_num++;
        }
        else {
            if (is_word) {
                is_word = 0;
                word_num++;
            }
        }
    }
    
    cout << word_num << endl;

    return 0;
}