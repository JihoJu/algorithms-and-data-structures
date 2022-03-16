// 직각삼각형
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp (const int a, const int b) {
    return a < b;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    while (true) {
        vector<int> sides(3);
        for (int i = 0; i < 3; i++)
            cin >> sides[i];
        
        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0) break;
        
        sort(sides.begin(), sides.end(), cmp);

        if (pow(sides[2], 2) ==  pow(sides[0], 2) + pow(sides[1], 2))
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }

    return 0;
}
