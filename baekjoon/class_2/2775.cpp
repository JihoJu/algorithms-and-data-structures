// 부녀회장이 될테야
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int test_case, k, n, cache = 0;
    vector<vector<int> > floor;
    vector<int> room;

    cin >> test_case;

    floor.push_back(room);
    for (int i = 1; i <= 14; i++)
        floor[cache].push_back(i);
    cache++;

    for (int i = 0; i < test_case; i++){
        cin >> k >> n;
        for (int j = cache; j <= k; j++) {
            floor.push_back(room);
            floor[j].push_back(1);
            for (int z = 1; z < 14; z++) {
                floor[j].push_back(floor[j][z - 1] + floor[j - 1][z]);
            }
            cache++;
        }
        cout << floor[k][n-1] << '\n';
    }
    
    return 0;
}