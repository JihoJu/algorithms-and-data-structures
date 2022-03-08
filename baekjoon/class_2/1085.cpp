// 직사각형에서 탈출 
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int x, y, w, h, min_distance;

    cin >> x >> y >> w >> h;

    if (x > (w / 2))
        x = w - x;
    if (y > (h / 2))
        y = h - y;
    
    min_distance = min(x, y);

    cout << min_distance << '\n';

    return 0;
}