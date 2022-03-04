// 최소, 최대
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, max = INT_MIN, min = INT_MAX;
    
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < vec.size(); i++){
        if (vec[i] > max)
            max = vec[i];
        if (vec[i] < min)
            min = vec[i];
    }

    cout << min << ' ' << max << '\n';

    return 0;
}