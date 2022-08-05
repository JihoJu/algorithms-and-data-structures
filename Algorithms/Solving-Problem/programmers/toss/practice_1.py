"""
dict(알파벳: 개수) -> 최대값 구하기
-> 리스트(알파벳, 개수) -> 최대값 이하 제거
-> 리스트 변환([알파벳, ]) -> 정렬 함수 생성 -> 결과값 반환

asda -> a
baaaabbbssdd -> ab
sqotdsdryetvtutsoowdeodevvsve -> TOSSdev
"""
import functools


def sorting_alphabet(a, b):
    if a == "T":
        return -1
    if b == "T":
        return 1
    if a == "O":
        return -1
    if b == "O":
        return 1
    if a == "SS":
        return -1
    if b == "SS":
        return 1

    if a < b:
        return -1
    else:
        return 1


def solution(s):
    answer = ""

    max_cnt = 0  # 가장 많이 쓰인 횟수
    alpha = dict()  # key: 알파벳, value: 쓰인 횟수
    for ch in s:
        if ch in ["T", "O", "S", "t", "o", "s"]:
            ch = ch.upper()
            if ch == "S":
                ch = "SS"
        else:
            ch = ch.lower()
        if ch not in alpha:
            alpha[ch] = 1
        else:
            alpha[ch] += 1
            max_cnt = max(max_cnt, alpha[ch])

    max_alpha = [a[0] for a in alpha.items() if a[1] >= max_cnt]

    max_alpha = sorted(max_alpha, key=functools.cmp_to_key(sorting_alphabet))

    answer = "".join(max_alpha)

    return answer
