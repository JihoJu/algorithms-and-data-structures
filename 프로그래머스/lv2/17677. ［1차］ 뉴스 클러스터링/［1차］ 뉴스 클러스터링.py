""" set 의 메서드 사용 x 풀이
def binary_search(target, S):
    left, right = 0, len(S) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if S[mid] == target:
            return 1
        elif S[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
            
    return -1

def solution(str1, str2):
    
    set_A = [str1[i:i + 2].lower() for i in range(len(str1) - 1) if str1[i:i + 2].isalpha()]
    set_B = [str2[i:i + 2].lower() for i in range(len(str2) - 1) if str2[i:i + 2].isalpha()]
    
    # 이진 탐색을 위해 정렬(오름차순)
    set_A.sort()
    set_B.sort()
    
    # 집합 A, B 모두 공집합인 경우
    if len(set_A) == 0 and len(set_B) == 0:
        return 65536
    
    # 교집합 구하기
    set_intersection = [elem for elem in set(set_A) if binary_search(elem, set_B) == 1]
    # 교집합 개수 처리
    intersection_cnt = sum(min(set_A.count(elem), set_B.count(elem)) for elem in set_intersection)
    
    # 합집합 처리
    exc_inters_cnt = len([elem for elem in set_A + set_B if elem not in set_intersection])
    inters_union_cnt = sum((max(set_A.count(elem), set_B.count(elem)) for elem in set_intersection))
    
    answer = int((intersection_cnt / (exc_inters_cnt + inters_union_cnt)) * 65536)

    return answer
"""

# set 메소드 사용 풀이
def solution(str1, str2):

    # zip 함수 사용
    A = [(c1 + c2).lower() for c1, c2 in zip(str1, str1[1:]) if (c1 + c2).isalpha()]
    B = [(c1 + c2).lower() for c1, c2 in zip(str2, str2[1:]) if (c1 + c2).isalpha()]
    
    # string index 연산
    # A = [str1[i:i + 2].lower() for i in range(len(str1) - 1) if str1[i:i + 2].isalpha()]
    # B = [str2[i:i + 2].lower() for i in range(len(str2) - 1) if str2[i:i + 2].isalpha()]

    # 집합 A, B 모두 공집합인 경우
    if len(A) == 0 and len(B) == 0:
        return 65536
    
    # 교집합 구하기
    set_intersection = set(A) & set(B)
    # 합집합
    set_union = set(A) | set(B)
    
    # 교집합 개수 처리
    inters_cnt = sum(min(A.count(elem), B.count(elem)) for elem in set_intersection)
    # 합집합 개수 처리
    union_cnt = sum(max(A.count(elem), B.count(elem)) for elem in set_union)
    
    answer = int((inters_cnt / union_cnt) * 65536)
    
    return answer