// 후보 추천하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, pair<int, int>> S;
int N, M;  // N: 사진틀의 개수, M: 전체 학생의 총 추천 횟수
vector<int> rec(1001);
deque<S> pic; // 학생번호, <추천 횟수, 사진틀에 걸린 시간>

// 추천 횟수 (내림차순), 사진틀에 걸린 시간 (오름차순)
bool cmp1(const S a, const S b) {
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    
    return a.second.first > b.second.first;
}

// 사진틀에 걸린 시간 + 1
void plus_time() {
    for (int i = 0; i < pic.size(); i++)
        pic[i].second.second++;
}

// 학생 번호 순 (오름차순)
bool cmp2(const S a, const S b) {
    return a.first < b.first;
}

// 추천 받은 학생이 사진틀에 있는 지 확인 후
// 있다면 index 번호 / 없다면 -1 리턴
int is_in(int student) {
    int index = -1;

    for (int i = 0; i < pic.size(); i++) {
        if (pic[i].first == student) {
            index = i;
            break;
        }
    }

    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> rec[i];

    for (int i = 0; i < M; i++) {
        int index = is_in(rec[i]);  // 추천 받은 학생이 사진틀에 있는지 확인
        // 추천 받은 학생이 사진틀에 있는 경우
        if (index != -1)
            pic[index].second.first++;
        // 추천 받은 학생이 사진틀에 없는 경우
        else {
            // 사진틀이 꽉찬 경우
            if (pic.size() >= N)
                pic.pop_back(); // 마지막 인덱스 학생 삭제
            pic.push_back(make_pair(rec[i], make_pair(1, 0)));
        }
        
        plus_time();    // 시간 + 1

        // 사진틀 정렬 (추천수 내림차순 (같다면 시간 오름차순))
        // 솔직히 이렇게 정렬을 매순간할 필요 x
        // 그냥 모든 사진틀을 탐색하며 삭제할 학생 찾아도 됨
        sort(pic.begin(), pic.end(), cmp1);
    }

    sort(pic.begin(), pic.end(), cmp2);
    for (int i = 0; i < pic.size(); i++)
        cout << pic[i].first << ' ';

    return 0;
}