// OX 퀴즈
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, score, acc;

    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < str.size(); i++) {
        score = 0;
        acc = 1;
        for (int j = 0; j < str[i].size(); j++) {
            if (str[i][j] == 'O') {
                score += acc;
                acc++;
            }
            else if (str[i][j] == 'X')
                acc = 1;
        }
        cout << score << '\n';
    }
    
    return 0;
}