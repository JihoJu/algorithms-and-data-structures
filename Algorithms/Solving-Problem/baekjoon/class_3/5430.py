import sys
from collections import deque

input = sys.stdin.readline


def print_result(arr, pointer):
    if pointer == -1:
        print("error")
        return
    print("[", end="")
    while len(arr):
        if pointer:
            print(arr.pop(), end="")
        else:
            print(arr.popleft(), end="")
        if len(arr):
            print(",", end="")

    print("]")


T = int(input())

for _ in range(T):
    func = input().strip()  # 함수 입력
    N = int(input())  # 배열 원소 개수
    arr = input().strip()  # 배열 입력

    arr = deque(arr[1:-1].split(","))  # 배열 string 전처리 후 deque으로 변환

    if N == 0:
        arr.pop()

    pointer = 0  # 0: 왼쪽, 1: 오른쪽
    for f in func:
        if f == "R":
            # 뒤집기
            pointer = 1 if pointer == 0 else 0
        else:  # D
            # 맨앞 원속 삭제
            if len(arr) == 0:
                pointer = -1
                break
            if pointer:
                arr.pop()
            else:
                arr.popleft()

    print_result(arr, pointer)
