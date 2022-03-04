// 니머지
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, count = 0;
    vector<int> vec(42, 0);

    for (int i = 0; i < 10; i++){
        cin >> n;
        vec[n % 42] += 1;
    }

    for (int i = 0; i < vec.size(); i++){
        if (vec[i])
            count++;
    }

    cout << count << '\n';

    return 0;
}