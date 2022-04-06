// 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<vector<int> > ARR;
ARR arr;
int N, M, x, y;

void print_arr(int n, ARR a);
void resize(int n, ARR &a);
void sol(int n, ARR &arr);
void mark(int n, int a, int b, ARR &arr);
int get_min_num(int n, ARR arr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    resize(N, arr);
    for (int i = 1; i <= N; i++)
        arr[i][i] = 0;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    sol(N, arr);

    return 0;
}

void mark(int n, int cnt, int a, int b, ARR &arr) {
    for (int i = 1; i <= n; i++) {
        if (arr[a][i] == 0 && arr[b][i] == 0 || arr[b][i] == INT_MAX) continue;
        if (arr[a][i] > arr[b][i] + cnt) {
            arr[a][i] = arr[b][i] + cnt;
            arr[i][a] = arr[a][i];
        }
    }
}

int get_min_num(int n, ARR arr) {
    int min_idx, min_value = INT_MAX, sum;
    
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += arr[i][j];
        }
        if (min_value > sum){
            min_value = sum;
            min_idx = i;
        } 
    }

    return min_idx;
}

void sol(int n, ARR &arr) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (arr[i][j] == 0 || arr[i][j] == INT_MAX) continue;
            mark(n, arr[i][j], i, j, arr);
        }
    }

    int min_idx = get_min_num(n, arr);

    cout << min_idx << '\n';
}

void resize(int n, ARR &a) {
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].resize(n + 1);
        fill(a[i].begin(), a[i].end(), INT_MAX);
    }
}

void print_arr(int n, ARR a) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}