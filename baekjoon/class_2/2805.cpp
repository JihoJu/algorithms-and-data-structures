// 나무 자르기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, max = 0;
    long long M;

    cin >> N >> M;

    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int low = 0, high = max, max_height, is_find = 0;
    long long mid;
    vector<int> heights;
    while (low <= high) {
        mid = (low + high) / 2;
        long long wood_num = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] <= mid) continue;
            else wood_num += (arr[i] - mid); 
        }

        if (wood_num == M) {
            is_find = 1;
            max_height = mid;
            break;
        }
        else if (wood_num > M){
            low = mid + 1;
            heights.push_back(mid);
        }
        else
            high = mid - 1;
    }

    if (!is_find) {
        sort(heights.begin(), heights.end(), cmp);
        max_height = heights[0];
    }
    
    cout << max_height << '\n';

    return 0;
}