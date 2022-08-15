// 트리의 높이와 너비
#include <iostream>
#include <climits>
#include <map>
#include <vector>

using namespace std;

int N;
map<int, pair<int, int> > tree;
vector<pair<int, int> > area;

void inorder(int ptr, int h);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int d, l, r;
    
    vector<int> is_root(N+1, 1);
    for (int i = 0; i < N; i++) {
        cin >> d >> l >> r;
        if (l != -1) is_root[l] = 0;
        if (r != -1) is_root[r] = 0;
        tree[d] = make_pair(l, r);
    }
    int root;
    for (int i = 1; i <= N; i++){
        if (is_root[i] == 1) {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int max_h = INT_MIN;
    for (int i = 0; i < area.size(); i++)
        if (area[i].second > max_h) max_h = area[i].second;

    pair<int, int> result = make_pair(0, INT_MIN); // (h, w)
    for (int h = 1; h <= max_h; h++) {
        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < area.size(); i++) {
            if (h != area[i].second) continue;
            if (i < start) start = i;
            if (i > end) end = i;
        }
        int w = end - start + 1;
        if (start == end)
            w = 1;
        if (w > result.second) {
            result.first = h;
            result.second = w;
        }
    }

    cout << result.first << ' ' << result.second << '\n';

    return 0;
}

void inorder(int ptr, int h) {
    if (ptr != -1) {
        inorder(tree[ptr].first, h+1);
        area.push_back(make_pair(ptr, h));
        inorder(tree[ptr].second, h+1);
    }
}
