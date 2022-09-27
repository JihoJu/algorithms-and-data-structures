// 트리 순회
#include <iostream>
#include <map>

using namespace std;

int N;
map<char, pair<char, char> > tree;

void preorder(char ptr);
void inorder(char ptr);
void postorder(char ptr);

int main() {

    cin >> N;
    char name, left, right;
    for (int i = 0 ; i < N; i++) {
        cin >> name >> left >> right;
        tree[name] = make_pair(left, right);
    }

    preorder('A'); cout << endl;
    inorder('A'); cout << endl;
    postorder('A'); cout << endl;

    return 0;
}

void preorder(char ptr) {
    if (ptr != '.') {
        cout << ptr;
        preorder(tree[ptr].first);
        preorder(tree[ptr].second);
    }
}
void inorder(char ptr) {
    if (ptr != '.') {
        inorder(tree[ptr].first);
        cout << ptr;
        inorder(tree[ptr].second);
    }
}
void postorder(char ptr) {
    if (ptr != '.') {
        postorder(tree[ptr].first);
        postorder(tree[ptr].second);
        cout << ptr;
    }
}