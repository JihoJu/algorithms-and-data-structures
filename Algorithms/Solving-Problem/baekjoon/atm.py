""" 11399번 - ATM 문제 """

"""
    1 2 3 3 4
    
    1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 3) + (1 + 2 + 3 + 3 + 4)
    1 + (1 + 2) + ()
    1, 3, 6
    이렇게 보고 아하~ 
    1. 리스트 오름 차순 정렬
    2. 해당 리스트 index 까지 다 합한 후 list 에다가 append!!
"""

num = int(input())
each_withdrawal_time = list(map(int, input().split()))

sorted_time = sorted(each_withdrawal_time, reverse=False)
total_time = 0
withdrawal_time = list()

for i in range(len(sorted_time)):
    withdrawal_time.append(sum(sorted_time[:i + 1]))

total_time = sum(withdrawal_time)

print(total_time)
