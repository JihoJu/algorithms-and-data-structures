// 숨바꼭질 bfs 풀이
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

#define R_LIMIT 100000

using namespace std;

vector<int> arr(100001, 0);
deque<pair<int, int> > dq;
int N, K;
int pos[3] = {-1, 1, 2};

int sol(int n, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    if (N == K) cout << 0 << '\n';
    else cout << sol(N, K) << '\n';

    return 0;
}

int sol(int n, int k) {
    int is_find = 0, order = 0;

    dq.push_back(make_pair(n, order));
    arr[n] = -1;    // 시작 위치 -1
    while (!is_find) {
        int num = dq.front().first;
        int order = dq.front().second + 1, m;
        dq.pop_front();
        
        for (int i = 0; i < 3; i++) {
            if (i < 2) m = num + pos[i];
            else m = num * pos[i];
            if (m >= 0 && m <= R_LIMIT && !arr[m]) {
                dq.push_back(make_pair(m, order));
                arr[m] = order;
                if (m == k) is_find = 1;
            }
        }
    }

    return arr[k];
}