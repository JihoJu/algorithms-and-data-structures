// 절댓값 힙
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

// 첫 번째 값을 기준으로 오름차순, 첫 번째 값이 같다면 두 번째 값을 기준으로 정렬
struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first > b.first;
        }
    }
};

int N;
vector<int> arr(100001);
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        // 가장 작은 값 출력
        if (!arr[i]) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
            pq.push(make_pair(abs(arr[i]), arr[i]));
    }

    return 0;
}