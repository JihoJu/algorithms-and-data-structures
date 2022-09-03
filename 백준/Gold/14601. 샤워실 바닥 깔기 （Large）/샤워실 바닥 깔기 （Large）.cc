// 샤워실 바닥 깔기 (Large)
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > TILE;
typedef pair<int, int> HOLE;
int order = 1;

void resize(int n, TILE &tile);
void print_tile(int n, TILE tile);
void solution(int n, TILE &tile, HOLE hole);
void partition(int n, TILE tile, TILE &h11, TILE &h12, TILE &h21, TILE &h22);
void combine(int n, TILE &tile, TILE t11, TILE t12, TILE t21, TILE t22);
int get_hole_position(int n, HOLE hole);
void laying_tile(int n, TILE &tile);
void laying_tile_specific_space(TILE &tile, HOLE hole);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    TILE tile;
    int K, N, x, y;

    cin >> K >> x >> y;

    N = 1 << K;

    resize(N, tile);
    tile[y - 1][x - 1] = -1;    // 하수구 위치

    solution(N, tile, make_pair(y - 1, x - 1));
    print_tile(1 << K, tile);

    return 0;
}

void solution(int n, TILE &tile, HOLE hole) {
    TILE T11, T12, T21, T22;
    HOLE h11, h12, h21, h22;

    if (n <= 2) {
        // 타일 깔기
        laying_tile(n, tile);
    }
    else {
        int m = n / 2;
        // partition
        partition(m, tile, T11, T12, T21, T22);
        // hole 이 어떤 분면에 있는지 확인
        int pos = get_hole_position(m, hole);
        h11 = make_pair(m - 1, m -1); h12 = make_pair(m - 1, 0); h21 = make_pair(0, m - 1); h22 = make_pair(0, 0);
        // hole 위치에 따라 tile 칠하기
        switch (pos) {
            case 1:
                h11.first = hole.first;
                h11.second = hole.second;
                laying_tile_specific_space(T12, h12);
                laying_tile_specific_space(T21, h21);
                laying_tile_specific_space(T22, h22);
                break;
            case 2:
                h12.first = hole.first;
                h12.second = hole.second - m;
                laying_tile_specific_space(T11, h11);
                laying_tile_specific_space(T21, h21);
                laying_tile_specific_space(T22, h22);
                break;
            case 3:
                h21.first = hole.first - m;
                h21.second = hole.second;
                laying_tile_specific_space(T11, h11);
                laying_tile_specific_space(T12, h12);
                laying_tile_specific_space(T22, h22);
                break;
            case 4:
                h22.first = hole.first - m;
                h22.second = hole.second - m;
                laying_tile_specific_space(T11, h11);
                laying_tile_specific_space(T12, h12);
                laying_tile_specific_space(T21, h21);
                break;
        }
        order++;
        // 재귀 호출
        solution(m, T11, h11); solution(m, T12, h12); solution(m, T21, h21); solution(m, T22, h22);
        // combine
        combine(m, tile, T11, T12, T21, T22);
    }
}

void combine(int n, TILE &tile, TILE t11, TILE t12, TILE t21, TILE t22) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tile[i][j] = t11[i][j];
            tile[i][j + n] = t12[i][j];
            tile[i + n][j] = t21[i][j];
            tile[i + n][j + n] = t22[i][j];
        }
    }
}

void partition(int n, TILE tile, TILE &t11, TILE &t12, TILE &t21, TILE &t22) {
    resize(n, t11); resize(n, t12); resize(n, t21); resize(n, t22);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t11[i][j] = tile[i][j];
            t12[i][j] = tile[i][j + n];
            t21[i][j] = tile[i + n][j];
            t22[i][j] = tile[i + n][j + n];
        }
    }
}

int get_hole_position(int n, HOLE hole) {
    if (hole.first < n && hole.second < n) return 1;
    else if (hole.first < n && hole.second >= n) return 2;
    else if (hole.first >= n && hole.second < n) return 3;
    else return 4;
}

void laying_tile_specific_space(TILE &tile, HOLE hole) {
    tile[hole.first][hole.second] = order;
}

void laying_tile(int n, TILE &tile) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tile[i][j] == -2) tile[i][j] = order;
        }
    }
    order++;
}

void print_tile(int n, TILE tile) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << tile[i][j];
            if (j != n - 1) cout << ' ';
            else cout << '\n';
        }
    }
}

void resize(int n, TILE &tile) {
    tile.resize(n);
    for (int i = 0; i < n; i++) {
        tile[i].resize(n);
        fill(tile[i].begin(), tile[i].end(), -2);
    }
}