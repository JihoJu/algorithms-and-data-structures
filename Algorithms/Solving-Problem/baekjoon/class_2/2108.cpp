// 통계학
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp (const int a, const int b) {
    return a < b;
}

bool freq_cmp (const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;

    return p1.second > p2.second;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, sum, elem_freq_idx, range;
    double avg;
    pair<int, int> p, most_freq_num;
    vector<pair<int, int> > elem_freq;

    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    avg = floor(((double)sum / n) + 0.5);
    
    sort(vec.begin(), vec.end(), cmp);
    
    elem_freq_idx = 0;
    elem_freq.push_back(make_pair(vec[0], 1));
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == elem_freq[elem_freq_idx].first) {
            elem_freq[elem_freq_idx].second++;
        }
        else {
            elem_freq.push_back(make_pair(vec[i], 1));
            elem_freq_idx++;
        }
    }
    
    sort(elem_freq.begin(), elem_freq.end(), freq_cmp);

    most_freq_num = elem_freq[0];
    for (int i = 1; i < elem_freq.size(); i++) {
        if (most_freq_num.second != elem_freq[i].second) break;
        else {
            most_freq_num = elem_freq[i];
            break;
        }
    }

    range = vec[vec.size() - 1] - vec[0];

    cout << avg << '\n' << vec[(n - 1) / 2] << '\n' << most_freq_num.first << '\n' << range << '\n';

    return 0;
}