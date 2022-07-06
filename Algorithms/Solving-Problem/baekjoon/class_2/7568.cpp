// 덩치
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int> > arr(n);
    vector<int> rank(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        rank[i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].first > arr[j].first && arr[i].second > arr[j].second)
                rank[j]++;
            else if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                rank[i]++;
        }
    }

    for (int i = 0; i < n; i ++) {
        cout << rank[i];
        if (i != n - 1) cout << ' ';
        else cout << '\n';
    }

    return 0;
}