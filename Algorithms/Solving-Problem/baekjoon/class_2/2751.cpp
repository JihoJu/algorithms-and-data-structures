// 수 정렬하기 2
#include <iostream>
#include <vector>

using namespace std;

int i, n;
vector<int> arr;

void merge(int low, int mid, int high) {
    vector<int> tmp(high - low + 1);
    int l = low, h = mid + 1, k = 0;

    while (l <= mid && h <= high)
        tmp[k++] = (arr[l] <= arr[h]) ? arr[l++] : arr[h++];

    for (; l <= mid; l++)
        tmp[k++] = arr[l];
    for (; h <= high; h++)
        tmp[k++] = arr[h];

    k = 0;
    for (; low <= high; low++)
        arr[low] = tmp[k++];
}

void mergesort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    arr.resize(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    mergesort(0, n - 1);

    for (i = 0; i < n; i++)
        cout << arr[i] << '\n';


    return 0;
}