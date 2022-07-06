// 프린터 큐
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

void clear_pq(priority_queue<pair<int, int> > &pq) {
    priority_queue<pair<int, int> > empty;
    swap(pq, empty);
}

void clear_dq(deque<pair<int, int> > &dq) {
    deque<pair<int, int> > empty;
    swap(dq, empty);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int case_num, n, m, input_import, import_num, import_freq, count, is_find; // n: 문서 개수 | m: 해당 문서가 몇 번째 놓여 있는지
    priority_queue<pair<int, int> > pq;
    deque<pair<int, int> > dq;
    pair<int, int> p;

    cin >> case_num;

    for (int c = 0; c < case_num; c++) {
        cin >> n >> m;

        clear_dq(dq);
        clear_pq(pq);
        
        vector<int> import_arr(10, 0);  // 중요도를 나타냄
        for (int i = 0; i < n; i++) {
            cin >> input_import;
            import_arr[input_import]++;
            dq.push_back(make_pair(i, input_import));
        }

        for (int i = 1; i < import_arr.size(); i++) {
            if (import_arr[i] == 0) continue;
            pq.push(make_pair(i, import_arr[i]));
        }
        
        count = 0;
        is_find = 0;
        while (!pq.empty()) {
            import_num = pq.top().first;
            import_freq = pq.top().second;
            while (import_freq) {
                p = dq.front();
                dq.pop_front();
                if (p.second == import_num) {
                    import_freq--;
                    count++;
                    if (p.first == m) {
                        is_find = 1;
                        break;
                    }
                }
                else {
                    dq.push_back(p);
                }
            }
            if (is_find) break;
            pq.pop();
        }

        cout << count <<'\n';
    }

    return 0;
}
