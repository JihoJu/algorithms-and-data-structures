// 평균
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    double sum = 0, avg;

    cin >> n;
    vector<int> score(n);

    for (int i = 0; i < n; i++){
        scanf("%d", &score[i]);
    }

    int largest = score[0];
    for (int i = 1; i < n; i++) {
        if (score[i] > largest)
            largest = score[i];
    }

    for (int i = 0; i < n; i++) {
        sum += ((double)score[i]/largest * 100);
    }

    avg = (double)sum / n;

    cout.precision(3);
    cout << avg << endl;

    return 0;
}