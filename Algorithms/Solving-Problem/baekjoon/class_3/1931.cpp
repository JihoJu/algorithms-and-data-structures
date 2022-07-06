// 회의실 배정 문제
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct conference
{
    int start, end;
};

int N, cnt = 1;
vector<conference> arr, selected;

bool cmp(conference a, conference b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.resize(N);    
    for (int i = 0 ; i < N ; i++)
        cin >> arr[i].start >> arr[i].end;

    sort(arr.begin(), arr.end(), cmp);

    selected.push_back(arr[0]);
    for (int i = 1; i < N; i++) {
        if (arr[i].start < selected.back().end) {
            continue;
        }
        else {
            selected.push_back(arr[i]);
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}