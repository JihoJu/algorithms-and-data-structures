// 잃어버린 괄호
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>

using namespace std;

typedef vector<vector<int> > T;
string input;
vector<int> sign, num, D;
T m;

void resize(int n, T &t);
void sol(int n);
int minimum(int n, int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    string s;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+' || input[i] == '-') {
            if (input[i] == '+') sign.push_back(1);
            else sign.push_back(-1);
            num.push_back(stoi(s));
            s.clear();
        }
        else 
            s += input[i];
    }
    num.push_back(stoi(s));

    resize(num.size(), m);
    for (int i = 0; i < num.size(); i++)
        m[i+1][i+1] = num[i];
    
    D.resize(sign.size() + 2);
    copy(sign.begin(), sign.end(), D.begin() + 2);

    sol(num.size());

    cout << m[1][num.size()] << '\n';

    return 0;
}

int minimum(int n, int i, int j) {
    int min_value = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int value = m[i][k] + (D[k+1] * m[k+1][j]);
        if (min_value > value) min_value = value;
    }

    return min_value;
}

void sol(int n) {
    for (int k = 1; k <= n - 1; k++) {
        for (int i = 1; i <= n - k; i++) {
            int j = i + k;
            m[i][j] = minimum(n, i, j);
        }
    }
}

void resize(int n, T &t) {
    t.resize(n + 1);
    for (int i = 1; i <= n; i++)
        t[i].resize(n + 1);
}
