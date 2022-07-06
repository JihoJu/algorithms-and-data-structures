// 차이를 최대로
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int N, max_value = INT_MIN;
vector<int> arr, w, visited;

int cal();
void solution(int i);
bool promising(int i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N + 1); w.resize(N + 1); 
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), 0);
    solution(0);
    cout << max_value << '\n';
    
}

void solution(int i) {
    if (i == N) {
        max_value = max(cal(), max_value);
    }
    else {
        for (int j = 1; j <= N; j++) {
            if (!visited[j]) {
                w[i + 1] = arr[j];
                visited[j] = 1;
                solution(i + 1);
                visited[j] = 0;
            }
        }
    }
}

int cal() {
    int res = 0;
    for (int i = 1; i <= N - 1; i++) {
        res += abs(w[i] - w[i + 1]);
    }

    return res;
}