// 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if (a.size() == b.size())
            return a < b;
    
    return a.size() < b.size();
}

bool is_exist(vector<string> words, string word){
    for (int i = 0; i < words.size(); i++){
        if (word == words[i])
            return true;
    }

    return false;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int num;
    string input;

    cin >> num;

    vector<string> words(num);

    for (int i = 0; i < num; i++)
        cin >> words[i];
    
    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < num; i++){
        if (i != 0 && words[i-1] == words[i])
            continue;            
        cout << words[i] << '\n';
    }

    return 0;
}