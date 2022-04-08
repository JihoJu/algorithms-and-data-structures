// 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
string name;
map<int, string> dogam_1;   // key: obs
map<string, int> dogam_2;   // key: name

bool isNumber(const string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i]) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int obs = 1;
    for (int i = 0; i < N; i++) {
        cin >> name;
        dogam_1.insert(make_pair(obs, name));
        dogam_2.insert(make_pair(name, obs++));
    }

    for (int i = 0; i < M; i++) {
        cin >> name;
        if (isNumber(name))
            cout << dogam_1.find(stoi(name))->second << '\n'; 
        else
            cout << dogam_2.find(name)->second << '\n';
    }
}   