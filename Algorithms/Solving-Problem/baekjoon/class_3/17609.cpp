// 회문
#include <iostream>
#include <string>

using namespace std;

int T;  // 문자열 개수
string input;
// 삭제시 왼쪽, 오른쪽 index 이동 배열
int del_l[2] = {1, 0}; 
int del_r[2] = {0, -1};

int solution(string S) {
    int res;    // 판단 결과

    for (int i = 0; i < 2; i++) {   // 왼쪽, 오른쪽 각각 문자 삭제를 위한 loop
        int left = 0, right = S.size() - 1; // left, right 각각 문자열 왼쪽, 오른쪽 끝 index
        res = 0;    // 일단 회문이라 가정
        int del_cnt = 0; // 문자 삭제 횟수

        while (left < right) {
            if (S[left] != S[right]) {
                // 이미 한번 문자를 삭제한 경우
                if (del_cnt) {
                    res = 2;
                    break;
                }
                if (left + del_l[i] < right + del_r[i] && S[left + del_l[i]] == S[right + del_r[i]]) {
                    left += del_l[i];   // 왼쪽 index 이동 (이전 문자 삭제 가정)
                    right += del_r[i];  // 오른쪽 index 이동
                    del_cnt++;  // 삭제 횟수 + 1
                    res = 1;    // 한번 삭제를 했으니 유사회문이라 가정
                }
                // 삭제를 해도 문자가 다를 경우
                else {
                    res = 2;
                    break;
                }
            }
            // 왼쪽, 오른쪽 문자가 같은 경우
            else {
                left++;
                right--;
            }
        }
        // 회문 or 유사 회문인 경우 왼, 오 각각 삭제 loop break
        if (res != 2)
            break;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> input;
        cout << solution(input) << '\n';
    }

    return 0;
}
