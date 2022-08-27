#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int s : scoville)
        pq.push(s);
    
    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int new_food = (f + (s * 2));
        pq.push(new_food);
        answer++;
    }
    
    return answer;
}