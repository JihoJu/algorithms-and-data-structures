/* N 찍기
for문 문제를 풀기 전에 주의해야할 점
입출력 방식이 느리면 여러 줄을 입력받거나 출력할 때 시간초과가 날 수 있다.
c++ 을 사용하고 있고 cin/cout 을 사용하고자 한다면,
- cin.sync_with_stdio(false);
- cin.tie(0);
을 둘 다 적용
- endl 대신 개행문자 (\n) 을 쓰자!!
*/
#include <iostream>

using namespace std;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << "\n";
    }

    return 0;
}