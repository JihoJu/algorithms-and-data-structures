// 프린터 큐
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#include <queue>

using namespace std;

void clear_pq(priority_queue<pair<int, int> > &q )
{
   priority_queue<pair<int, int> > empty;
   swap(q, empty);
}

void clear_dq(deque<pair<int, int> > &dq)
{
   deque<pair<int, int> > empty;
   swap(dq, empty);
}

void clear_set(set<int> &s) {
    set<int> empty;
    swap(s, empty);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int case_num, n, m, order, is_find, priority, count;
    set<int> priority_set;
    pair<int, int> p, dp_pair;
    priority_queue<pair<int, int> > pq;
    deque<pair<int, int> > dq;

    cin >> case_num;

    for (int i = 0; i < case_num; i++) {
        cin >> n >> m;
        order = 0;
        is_find = 0;
        clear_pq(pq);
        clear_dq(dq);
        clear_set(priority_set);

        for (int j = 0; j < n; j++) {
            cin >> priority;
            p = make_pair(j, priority);
            dq.push_back(p);
            priority_set.insert(priority);
        }
        
        for (set<int>::iterator iter = priority_set.begin(); iter != priority_set.end(); iter++) {
            count = 0;
            for (int j = 0; j < dq.size(); j++) {
                if (dq[j].second == *iter) count++;
                    
            }
            p = make_pair(*iter, count);
            pq.push(p);
        }

        while (!is_find && !pq.empty()) {
            p = pq.top();
            count = p.second; // 우선 순위를 가진 종이 개수
            while (!is_find && count > 0) {
                dp_pair = dq.front();
                dq.pop_front();
                if (dp_pair.second == p.first) {
                    order++;
                    if (dp_pair.first == m) is_find = 1;
                    count--;
                }
                else
                    dq.push_back(dp_pair);
            }
            pq.pop();
        }
        
        cout << order << '\n';
    }

    return 0;
}