"""
    Greedy Algorithm
        - 최적의 해에 가까운 값을 구하기 위해 사용
        - 여러 경우 중 하나를 결정해야할 때마다, 매순간 최적이라고 생각되는 경우를 선택하는 방식으로 진행 후, 최종적인 값을 구하는 방식
        - ex) 여러 경로 중 가장 짧은 경로를 선택해야할 경우
        - 한계가 존재 -> 무조건 최적의 해를 구하는 것이 아님 -> 근사치 추정을 가능하게 해준다!
"""


def coin_problem():
    """ 동전 문제

    지불 해야 하는 값이 4720원 : 1원, 50원, 100원, 500원 동전으로 동전의 수 가장 적게 지불
    """

    pay_money = 4720
    total_coin_count = 0
    coin_kinds = [1, 50, 100, 500]
    coin_num = dict()

    while pay_money > 0:
        coin = max(coin_kinds)
        coin_kinds.pop(coin_kinds.index(coin))
        # 혹은 list 자체를 정렬 후 pop() or pop(0) 해도 됨
        # coin_kinds.sort(reverse=True)

        num = pay_money // coin
        total_coin_count += num
        pay_money -= coin * num
        coin_num[coin] = num

    for c in coin_num:
        print(c, coin_num[c])
    print("total : ", total_coin_count)


def fractional_knapsack_problem(capacity):
    """ 부분 배낭 문제
        
    무게 제한이 k인 배낭에 최대 가치를 가지도록 물건을 넣는 문제
    - 각 물건은 무게 (w) / 가치 (v)
    - 물건은 쪼갤 수 있으므로 물건의 일부분이 배낭에 넣어질 수 있음 => 그래서 fractional_knapsack_problem 라고 함
        - Fractional Knapsack Problem 의 반대로 물건을 쪼개서 넣을 수 없는 배낭 문제도 존재 => 0/1 Knapsack Problem
    """

    data_list = [(10, 10), (15, 12), (20, 10), (25, 8), (30, 5)]  # (무게, 가치)

    data_list = sorted(data_list, key=lambda x: x[1] / x[0], reverse=True)  # 무게 단위 당 가치가 높은 순으로 정렬

    """
    total_value = 0
    total_weight = 0
    
    while True:
        knapsack_w, knapsack_v = data_list.pop(0)
        if (total_weight + knapsack_w) > capacity:
            interval = capacity - total_weight
            total_weight += interval
            total_value += ((knapsack_v / knapsack_w) * interval)
            break
        else:
            total_value += knapsack_v
            total_weight += knapsack_w

    print("capacity", capacity)
    print("total_value", total_value)
    print("total_weight", total_weight)
    """
    total_value = 0

    for data in data_list:
        if capacity <= 0:
            break
        if capacity - data[0] >= 0:
            print("capacity : ", capacity)
            capacity -= data[0]
            total_value += data[1]
            print("weight : ", data[0])
            print("total value : ", total_value)
        else:
            print("capacity : ", capacity)
            print("weight : ", data[0])
            fraction = capacity / data[0]
            total_value += (data[1] * fraction)
            capacity -= (data[0] * fraction)
            print("fraction : ", fraction)
            print("total value : ", total_value)


fractional_knapsack_problem(30)
