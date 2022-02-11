import random


def sequential_search(data: list, search_data: int):
    """ 순차 탐색 """

    for item in data:
        if item == search_data:
            return True
    return False


def binary_search(data: list, search_data: int):
    """ 이진 탐색 """

    if len(data) == 1:
        if data[0] == search_data:
            return True
        else:
            return False

    medium = len(data) // 2

    if data[medium] == search_data:
        return True
    elif search_data < data[medium]:
        return binary_search(data[:medium], search_data)
    else:
        return binary_search(data[medium + 1:], search_data)


input_list = list(random.sample(range(100), 10))
input_list.sort()

search = 10

if binary_search(input_list, search):
    print("ok!!")
else:
    print("no!!")
