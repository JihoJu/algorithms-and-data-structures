// 연구소
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>
using namespace std;

int N, M, maxValue = INT_MIN;
vector<vector<int>> arr;
vector<pair<int, int>> emptyList, selected, epidemic;
deque<pair<int, int>> dq;

// 상하좌우
int move_row[4] = {-1, 1, 0, 0};
int move_col[4] = {0, 0, -1, 1};

void get_empty_area(vector<vector<int>> MAP);
void resize();
int get_safe_area(vector<vector<int>> MAP);
void solution(int i);
bool is_exist(int i, pair<int, int> p);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    resize();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
    }
    get_empty_area(arr);
    selected.resize(4);

    solution(0);
    cout << maxValue << '\n';

    return 0;
}

void get_empty_area(vector<vector<int>> MAP) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 2) {
                epidemic.push_back(make_pair(i, j));
                dq.push_back(make_pair(i, j));
                while (!dq.empty()) {
                    pair<int, int> ord = dq.front();
                    dq.pop_front();
                    for (int k = 0; k < 4; k++) {
                        int row = ord.first + move_row[k];
                        int col = ord.second + move_col[k];
                        if (row >= 1 && row <= N && col >= 1 && col <= M && arr[row][col] == 0 && MAP[row][col] != 3) {
                            dq.push_back(make_pair(row, col));
                            emptyList.push_back(make_pair(row, col));
                            MAP[row][col] = 3;  // 이미 전염병이 퍼진 곳
                        }
                    }
                }
            }
        }
    }
}

int get_safe_area(vector<vector<int>> MAP) {
    for (int i = 1; i <= 3; i++) {
        MAP[selected[i].first][selected[i].second] = 1;
    }
    for (pair<int, int> p: epidemic) {
        dq.push_back(make_pair(p.first, p.second));
        while (!dq.empty()) {
            pair<int, int> ord = dq.front();
            dq.pop_front();
            for (int k = 0; k < 4; k++) {
                int row = ord.first + move_row[k];
                int col = ord.second + move_col[k];
                if (row >= 1 && row <= N && col >= 1 && col <= M && MAP[row][col] == 0 && MAP[row][col] != 3) {
                    dq.push_back(make_pair(row, col));
                    MAP[row][col] = 3;  // 이미 전염병이 퍼진 곳
                }
            }
        }
    }
    int safe = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (MAP[i][j] == 0)
                safe++;
        }
    }

    return safe;
}

bool is_exist(int i, pair<int, int> p) {
    int j = 1;
    while (j <= i) {
        if (selected[j].first == p.first && selected[j].second == p.second) 
            return false;
        j++;
    }
    return true;
}

void solution(int i) {
    if (i == 3) {
        // bfs 계산
        maxValue = max(maxValue, get_safe_area(arr));
    }       
    else {
        for (int j = 0; j < emptyList.size(); j++) {
            if (is_exist(i, emptyList[j])) {    // 항상 중복되는 값을 고려해야된다!!!
                selected[i + 1] = emptyList[j];
                solution(i + 1);
            }
        }
    }
}

void resize() {
    arr.resize(N + 1);
    for (int i = 1; i <= N; i++)
        arr[i].resize(M + 1);
}