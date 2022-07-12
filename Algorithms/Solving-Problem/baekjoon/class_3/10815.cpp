// 숫자 카드
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> cards;

bool cmp(const int a, const int b) {
    return a < b;
}

int is_having(int n) {
    int start = 0, end = N - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (cards[mid] == n)
            return 1;
        else if (n < cards[mid]) 
            end = mid - 1;
        else
            start = mid + 1;
    }

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cards.resize(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];

    sort(cards.begin(), cards.end(), cmp);

    cin >> M;
    int input;
    for (int i = 0; i < M; i++) {
        cin >> input;
        cout << is_having(input) << ' ';
    }

    return 0;
}