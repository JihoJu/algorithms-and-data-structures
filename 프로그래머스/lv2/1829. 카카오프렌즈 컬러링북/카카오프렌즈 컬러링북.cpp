#include <iostream>
#include <vector>

using namespace std;

void dfs(int m, int n, int i, int j, int &size, vector<vector<int>> picture, vector<vector<int>> &visited) {
    if (i != 0 && picture[i-1][j] == picture[i][j] && visited[i-1][j] == 0) { // 상
        visited[i-1][j] = 1;
        size++;
        dfs(m, n, i-1, j, size, picture, visited);
    }
    if (i != m - 1 && picture[i+1][j] == picture[i][j] && visited[i+1][j] == 0) { // 하
        visited[i+1][j] = 1;
        size++;
        dfs(m, n, i+1, j, size, picture, visited);
    }
    if (j != 0 && picture[i][j - 1] == picture[i][j] && visited[i][j - 1] == 0) { // 좌
        visited[i][j-1] = 1;
        size++;
        dfs(m, n, i, j-1, size, picture, visited);
    }
    if (j != n - 1 && picture[i][j + 1] == picture[i][j] && visited[i][j + 1] == 0) { // 우
        visited[i][j+1] = 1;
        size++;
        dfs(m, n, i, j+1, size, picture, visited);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int>> visited(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visited[i][j] == 0) {
                cout << i << ' ' << j << ' ' << picture[i][j] << '\n';
                int max_size = 1;
                number_of_area++;
                visited[i][j] = 1;
                dfs(m, n, i, j, max_size, picture, visited);
                if (max_size > max_size_of_one_area) max_size_of_one_area = max_size;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}