// 카드2
#include <iostream>
#include <deque>

using namespace std;

int card2(deque<int> &dq) {
    int tmp;

    if (dq.size() <= 1) return dq.front();

    dq.pop_front();
    tmp = dq.front();
    dq.pop_front();
    dq.push_back(tmp);

    return card2(dq);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    deque<int> dq;

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    cout << card2(dq) << '\n';

    return 0;
}