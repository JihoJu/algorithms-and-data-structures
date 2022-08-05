#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
    /*
        cmp 가 true 를 반환하면 원소의 순서를 그대로 놔두고
        false 를 반환하면 원소를 swap 한다.
        
        a + b > b + a 가 true 라면 a, b 순서 그대로 두고
        a + b < b + a 라면 false 로 a, b 순서를 swap 한다.
    */
    return stoi(a + b) > stoi(b + a);
}

string convertToString(vector<string> arr) {
    string res = "";
    
    for (string s: arr)
        res += s;
    
    return res;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> ch_numbers;
    
    for (int num: numbers)
        ch_numbers.push_back(to_string(num));
    
    sort(ch_numbers.begin(), ch_numbers.end(), cmp);
    
    if (ch_numbers[0] != "0")
        answer = convertToString(ch_numbers);
    else
        answer = "0";
    
    return answer;
}