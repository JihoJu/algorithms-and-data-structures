
/* 체스판 다시 칠하기
    * 중요 포인트! : 정답이 있고 정답에 해당하게 고쳐야하는 개수를 구하는 문제는 정답을 미리 입력 후 비교하는 방향으로 가자!!
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m, count1, count2, smallest, col_idx, row_idx;

    cin >> n >> m;

    vector<int> modified_nums;
    char array[n][m];
    char right_array1[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
    };
    char right_array2[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
    };


    //체스판 입력
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
    }

    for (int r = 0; r + 7 < n; r++) {
        for (int c = 0; c + 7 < m; c++){
            count1 = 0;
            count2 = 0;
            row_idx = 0;
            col_idx = 0;
            for (int i = r; i < r + 8; i++){
                col_idx = 0;
                for (int j = c; j < c + 8; j++){
                    if (right_array1[row_idx][col_idx] != array[i][j])
                        count1++;
                    if (right_array2[row_idx][col_idx] != array[i][j])
                        count2++;
                    col_idx++;
                }
                row_idx++;
            }
            modified_nums.push_back(min(count1, count2));
        }
    }

    smallest = modified_nums[0];
    for (int i = 1; i < modified_nums.size(); i++) {
        if (modified_nums[i] < smallest)
            smallest = modified_nums[i];
    }

    cout << smallest << '\n';
    /*
    9 23
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBB
    BBBBBBBBBBBBBBBBBBBBBBW
    밑에 알고리즘을 사용하면 최소 값이 32 가 나온다.
    아래 알고리즘은 0,0 글자를 기준으로 수정할 체스 칸 개수를 센 것임.
        => 그냥 어차피 2가지 case 만이 존재하니 정답 체스판 2개를 저장하고 이를 비교하면서 
            다른 것만 개수를 세는 방향으로 가는 것이 좋을 듯,,,
    */
   /*
    for (int r = 0; r + 7 < n; r++) {
        for (int c = 0; c + 7 < m; c++){
            char ptr_ch = array[r][c];
            count = 0;
            for (int i = r; i < r + 8; i++){
                if (i != r && ptr_ch != array[i][c]) {
                    count++;
                }
                for (int j = c + 1; j < c + 8; j++){
                    if (ptr_ch == array[i][j])
                        count++;
                    if (ptr_ch == 'W') ptr_ch = 'B';
                    else if (ptr_ch == 'B') ptr_ch = 'W';
                }
            }
            modified_nums.push_back(count);
        }
    }
    for (int i = 0; i < modified_nums.size(); i++)
        cout << modified_nums[i] << '\n';
    */

    return 0;
}