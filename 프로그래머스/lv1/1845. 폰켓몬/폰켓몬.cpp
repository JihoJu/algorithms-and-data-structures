#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> M;

int solution(vector<int> nums)
{
    int answer = 0;
    for (int num: nums) {
        if (M.find(num) != M.end())
            M[num]++;
        else
            M[num] = 1;
    }
    
    answer = (M.size() > nums.size() / 2) ? nums.size() / 2 : M.size();
    
    return answer;
}