// 듣보잡
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, M;
string input;
map<string, int> m;
vector<string> vec;

bool cmp(const string a, const string b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        m[input] = 1;
    } 

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (m.find(input) != m.end()) {
            cnt++;
            vec.push_back(input);
        }
    }

    sort(vec.begin(), vec.end(), cmp);
    cout << cnt << '\n';
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << '\n';

    return 0;
}