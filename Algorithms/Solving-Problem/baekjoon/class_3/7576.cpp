// 토마토
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > T;
typedef vector<pair<int, int> > INDEX;
T toma;
INDEX idx, tmp;
int M, N, day, is_break, toma_num;

void resize(int n, int m, T &t);
void print_arr(int n, int m, T t);
int get_smallest_day (int n, int m, T t);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    toma_num = N * M;
    resize(N+2, M+2, toma);
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < M + 2; j++) {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1) toma[i][j] = -2;
            else {
                cin >> toma[i][j];
                if (toma[i][j] == 1 || toma[i][j] == -1) toma_num--;
            }
        }
    }

    if (toma_num == 0) {
        cout << 0 << '\n';
        return 0;
    }


    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (toma[i][j] == 1)
                idx.push_back(make_pair(i, j));
        }
    }

    day = 1;
    is_break = 0;
    pair<int, int> pos;
    while(toma_num) {
        while (!idx.empty()) {
            pos = idx.back();
            idx.pop_back();
            if (toma[pos.first][pos.second-1] == 0) {
                toma_num--;
                toma[pos.first][pos.second-1] = 1;
                tmp.push_back(make_pair(pos.first, pos.second - 1));
            }
            if (toma[pos.first][pos.second+1] == 0) {
                toma_num--;
                toma[pos.first][pos.second+1] = 1;
                tmp.push_back(make_pair(pos.first, pos.second + 1));
            }
            if (toma[pos.first-1][pos.second] == 0) {
                toma_num--;
                toma[pos.first-1][pos.second] = 1;
                tmp.push_back(make_pair(pos.first - 1, pos.second));
            }
            if (toma[pos.first+1][pos.second] == 0) {
                toma_num--;
                toma[pos.first+1][pos.second] = 1;
                tmp.push_back(make_pair(pos.first + 1, pos.second));
            }
        }
        idx = tmp;
        tmp.clear();
        day++;
        if (idx.empty()) {
            is_break = 1;
            break;
        }
    }

    int smallest_day;
    if (is_break) smallest_day = -1;
    else
        smallest_day = day - 1;

    cout << smallest_day << '\n';

    return 0;
}

void resize(int n, int m, T &t) {
    t.resize(n);
    for (int i = 0; i < n; i++) {
        t[i].resize(m);
        fill(t[i].begin(), t[i].end(), 0);
    }
}