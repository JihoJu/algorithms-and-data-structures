// 문자열 압축
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    
    int answer = INT_MAX, threshold;
    
    if (s.size() == 1) threshold = 2;
    else threshold = s.size();
    
    for (int c = 1; c < threshold; c++) { // 단어 묶는 개수
        int idx = 0;
        string tmp = "";
        while (idx < s.size()) {
            int end = idx + c, cnt = 1;
            if (end < s.size() && s.substr(idx, c) == s.substr(end, c)) {
                while (end < s.size() && s.substr(idx, c) == s.substr(end, c)) {
                    cnt++;
                    end += c;
                }
                tmp += (to_string(cnt) + s.substr(idx, c));
                idx = end;
            }
            else {
                if (end > s.size() - 1)
                    end = s.size();
                while (idx < end)
                    tmp += s[idx++];
            }   
        }
        // cout << tmp  << ' ' << tmp.size() << '\n';
        if (tmp.size() < answer) answer = tmp.size();
    }
    
    return answer;
}