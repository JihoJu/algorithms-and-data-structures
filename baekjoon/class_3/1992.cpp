// 쿼드트리
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> ARR;
int N;
ARR arr;

void resize();
bool is_exist_result(int s_row, int e_row, int s_col, int e_col, int &res);
void sol(int n, int s_row, int e_row, int s_col, int e_col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    resize();
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            arr[i][j] = input[j] - '0';
        }
    }
    
    sol(N, 0, N - 1, 0, N - 1);

    return 0;
}

bool is_exist_result(int s_row, int e_row, int s_col, int e_col, int &res) {
    res = arr[s_row][s_col];
    for (int i = s_row; i <= e_row; i++) {
        for (int j = s_col; j <= e_col; j++) {
            if (res != arr[i][j]) return false;
        }
    }

    return true;
}

void sol(int n, int s_row, int e_row, int s_col, int e_col) {
    int res = -1;

    if (n == 1) {
        cout << arr[s_row][s_col];
        return;
    }
    if (is_exist_result(s_row, e_row, s_col, e_col, res)) {
        cout << res;
    }
    else {
        int m = n / 2;
        cout << '(';
        sol(m, s_row, s_row + m - 1, s_col, s_col + m - 1);
        sol(m, s_row, s_row + m - 1, s_col + m, e_col);
        sol(m, s_row + m, e_row, s_col, s_col + m - 1);
        sol(m, s_row + m, e_row, s_col + m, e_col);
        cout << ')';
    }
}

void resize() {
    arr.resize(N);
    for (int i = 0; i < N; i++)
        arr[i].resize(N);
}