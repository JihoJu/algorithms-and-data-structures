//평범한 배낭 - dp (HashMap 사용)
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, K;
map<pair<int, int>, int> HASH;
vector<int> W, P;

int sol(int n, int w) {
    if (n == 0 || w <= 0)
        return 0;

    int lvalue = (HASH.find(make_pair(n-1, w)) != HASH.end()) ? HASH[make_pair(n-1, w)] : sol(n-1, w);
    int rvalue = (HASH.find(make_pair(n-1, w-W[n])) != HASH.end()) ? HASH[make_pair(n-1, w-W[n])] : sol(n-1, w-W[n]);
    HASH[make_pair(n, w)] = (W[n] > w) ? lvalue : max(lvalue, P[n] + rvalue);

    return HASH[make_pair(n, w)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    W.resize(N + 1); P.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> P[i];

    cout << sol(N, K) << '\n'; 
    
    return 0;
}