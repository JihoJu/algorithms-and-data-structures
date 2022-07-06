// 숫자 카드 2
#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, input;
    map<int, int> map;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (map.count(input))
            map[input] += 1;
        else
            map[input] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> input;

        if (map.count(input))   // map.count(key): key 는 ㄴ중복 x => 있으면 1 | 없으면 0 리턴
            cout << map[input];
        else
            cout << 0;

        if (i != m - 1) cout << ' ';
        else cout << '\n';
    }

    return 0;
}