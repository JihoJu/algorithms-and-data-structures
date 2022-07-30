#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 올바른 괄호 문자열인가?
bool is_proper(string p) {
    bool flag = true;
    int l = 0;
    for (char c: p) {
        if (c == '(') {
            l++;
        }
        else {  // ')' 의 경우
            if (l == 0) {
                flag = false;
                break;
            }
            l--;
        }
    }
    
    return flag;
}

// 문자열을 u, v 로 분리
void divide_string(string p, string &u, string &v) {
    int l = 0, r = 0, div = 0;
    
    for (int i = 0; i < p.size(); i++) {
        if (div) {
            v += p[i];
            continue;
        }
        if (p[i] == '(')
            l++;
        else    // ')'
            r++;
        
        u += p[i];
        
        if (l == r)
            div = 1;
    }
}

// 올바른 괄호 문자열 변활 과정
string processing(string p) {
    // 1번
    if (p.size() == 0)
        return "";
    // 2번
    string u = "", v = "", ret = "";
    divide_string(p, u, v);
    // 3번
    if (is_proper(u)) {
        ret += u;
        ret += processing(v);
    }
    // 4번
    else {
        ret += "(";   // 4-1
        ret += processing(v);   // 4-2
        ret += ")"; // 4-3
        // 4-4
        for (int i = 1; i < u.size() - 1; i++) {    // 첫 번째 마지막 문자 제외
            if (u[i] == '(')
                ret += ')';
            else
                ret += '(';
        }
    }
    
    return ret;
}

string solution(string p) {
    string answer = "";
    
    if (is_proper(p)) {
        return p;
    }
    else {
        answer = processing(p);
    }
        
    return answer;
}