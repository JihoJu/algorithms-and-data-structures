#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string a, const string b) {
    int n;
    
    n = min(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        if (a[i] - '0' == b[i] - '0')
            continue;   
        else
            return (a[i] - '0') > (b[i] - '0');
    }
    
    string num1 = a + b, num2 = b + a;
    
    return stoi(num1) > stoi(num2);
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