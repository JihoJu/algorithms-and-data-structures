// 문자열 반복
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<int, string>> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vec[i].second.size(); j++) {
            for (int k = 0; k < vec[i].first; k++) {
                cout << vec[i].second[j];
            }
        }
        cout << endl;
    }

    return 0;
}