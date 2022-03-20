// 나이순 정렬
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, string> a, const pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, i, j;
    pair<int, string> tmp;

    cin >> n;
    vector<pair<int, string> > arr(n);

    for (i = 0; i < n; i++) {
        cin >> tmp.first >> tmp.second;
        arr[i] = tmp;
    }

    stable_sort(arr.begin(), arr.end(), cmp);
    
    for (i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second <<'\n';
    

    return 0;
}