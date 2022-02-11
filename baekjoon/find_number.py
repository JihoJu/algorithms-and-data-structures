import sys

""" 1920번 탐색 - 수 찾기 문제 """

input_num = int(sys.stdin.readline())
input_list = list(map(int, sys.stdin.readline().split(' ')))

search_num = int(sys.stdin.readline())
search_list = list(map(int, sys.stdin.readline().split(' ')))
input_list.sort()


def solution_1(input_data: list, search_data: int):
    """ 시간 초과 """

    if len(input_data) == 0:
        return 0

    if len(input_data) == 1:
        if input_data[0] == search_data:
            return 1
        else:
            return 0

    medium = len(input_data) // 2

    if search_data == input_data[medium]:
        return 1
    elif search_data < input_data[medium]:
        return solution_1(input_data[:medium], search_data)
    else:
        return solution_1(input_data[medium + 1:], search_data)


def solution_2(search_data, start, end):
    """ 시간 초과 """

    while start != end:
        middle = (start + end) // 2
        if input_list[middle] == search_data:
            return 1
        elif search_data < input_list[middle]:
            end = middle - 1
        else:
            start = middle + 1

    if input_list[start] == search_data:
        return 1

    return 0


def solution_3(search_data, start, end):
    """ 맞은 코드 """

    if start > end:  # 아마도 이 부분을 생각 안 해줘서 계속 시간 초과 (무한 루프 등) 가 발생한 거 같다.
        return 0
    elif start == end:
        if search_data == input_list[start]:
            return 1
        else:
            return 0
    else:
        middle = (start + end) // 2
        if search_data == input_list[middle]:
            return 1
        elif search_data < input_list[middle]:
            return solution_3(search_data, start, middle - 1)
        else:
            return solution_3(search_data, middle + 1, end)


for data in search_list:
    print(solution_3(data, 0, input_num - 1))
