// 스타트와 링크
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

int N;  // 사람 수
int answer = INT_MAX;
vector<vector<int>> player_stats(21, vector<int>(21));  // 선수 능력치
vector<int> team(21, 0);    // 팀
vector<int> t1, t2; // 나눈 팀

bool promising(int n) {
    bool flag = false;  // 팀이 이루어졌는 지 확인
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        // team[i] 가 1일 경우 cnt + 1
        if (team[i])
            cnt++;
    }
    // team에 1과 0이 N / 2로 나눠진 경우
    if (cnt == (N / 2))
        flag = true; 

    return flag;
}

// 팀 능력치 구하기
int get_team_value(vector<int> T) {
    int team_value = 0;
    
    for (int i = 0; i < T.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            team_value += player_stats[T[i]][T[j]];
        }
    }
    return team_value;
}

void sol(int n) {
    if (promising(n)) {
        t1.clear(); t2.clear();        
        for (int i = 1; i <= N; i++) {
            if (team[i])
                t1.push_back(i);    // 1인 경우
            else
                t2.push_back(i);    // 0인 경우
        }
        answer = min(answer, abs(get_team_value(t1) - get_team_value(t2)));
    }
    else {
        if (n <= N) {
            team[n] = 1;
            sol(n + 1);
            team[n] = 0;
            sol(n + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> player_stats[i][j];
    }

    sol(1);
    
    cout << answer << '\n';

    return 0;
}