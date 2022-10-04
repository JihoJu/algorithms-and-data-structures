// 마인크래프트
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}

bool pair_cmp(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M, B, v, min = 257, max = 0, inventory, time, is_no;
    vector<pair<int, int> > results;

    cin >> N >> M >> B;

    vector<int> arr(N * M);

    for (int i = 0; i < N*M; i++) {
        cin >> arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);
   
    while (min <= max) {
        is_no = 0;
        inventory = B;  // inventory 개수
        time = 0;   // 걸린 시간 카운트
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == min) continue;
            else if (arr[i] > min) { // 블록 빼기
                inventory += (arr[i] - min);
                time += ((arr[i] - min) * 2);   
            }
            else {  // 블록 올려두기
                inventory -= (min - arr[i]);
                if (inventory < 0) { 
                    is_no = 1;
                    break;
                }
                time += ((min - arr[i]) * 1);
            }
        }
        if (!is_no)
            results.push_back(make_pair(time, min));
        min++;
    }

    sort(results.begin(), results.end(), pair_cmp);

    cout << results[0].first << ' ' << results[0].second << '\n';

    return 0;
}