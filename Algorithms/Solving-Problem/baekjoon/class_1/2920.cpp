// 음계
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums(8);
    int is_asc = 0, is_des = 0;

    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] < nums[i])
            is_asc = 1;
        if (nums[i-1] > nums[i])
            is_des = 1;
    }

    if (is_asc && is_des)
        cout << "mixed" << '\n';
    else if (is_asc)
        cout << "ascending" << '\n';
    else 
        cout << "descending" << '\n';

    return 0;
}