// 피자 굽기 (이분 탐색)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int D, N;   // D: 오븐의 깊이, N: 피자의 반죽 개수
vector<int> depth(300001);
queue<int> dough;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> D >> N;
    for (int i = 1 ; i <= D; i++)
        cin >> depth[i];
        
    int r;
    for (int i = 0 ; i < N; i++) {
        cin >> r;
        dough.push(r);
    }

    // 1층 -> N층까지 도우의 지름이 층의 반지름보다 클 때 멈춘다.
    // 위 층의 지름이 아래층의 지름보다 작을 경우 아래층의 지름이 클 필요 x
    // 위에 층과 같이 만들어주는 작업 필요 -> 이분 탐색을 위해!  
    for (int i = 2 ; i <= D; i++) {
        if (depth[i - 1] < depth[i])
            depth[i] = depth[i - 1];
    }
    
    int top = D + 1;    // 도우가 들어간 최상층 (최상층 D + 1) 가정 -> 아무런 도우가 들어가 있지 않다.
    while (!dough.empty()) {
        int floor;
        int left = 1, right = top;
        // 이분 탐색
        while (left <= right) {
            int mid = (left + right) / 2;

            if (dough.front() <= depth[mid]) {
                left = mid + 1;
                if (left >= top) {
                    floor = top - 1;
                }
            }
            else {
                floor = mid - 1;
                right = mid - 1;
            }
        }
        
        if (floor <= 0)
            break;
        else {
            dough.pop();
            if (floor > top)
                top--;
            else
                top = floor;
        }
    }

    if (!dough.empty())
        top = 0;
    
    cout << top << '\n';

    return 0;
}   