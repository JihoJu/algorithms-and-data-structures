// X보다 작은 수
#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, x;

    cin >> n >> x;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n; i++){
        if (vec[i] < x)
            cout << vec[i] << ' ';
    }

    return 0;
}