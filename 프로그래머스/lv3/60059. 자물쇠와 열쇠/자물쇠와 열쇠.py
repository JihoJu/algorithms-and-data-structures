from copy import deepcopy

def solution(key, lock):
    N, M, cnt = len(lock), len(key), 0   # lock, key 크기 / cnt: 홈 개수
    # lock * 3 2차원 배열 생성
    MAP = [[2] * (N * 3) for _ in range(N * 3)]
    for i in range(N):
        for j in range(N):
            MAP[i + N][j + N] = lock[i][j]
            if lock[i][j] == 0:
                cnt += 1
    
    for i in range(N - M + 1, N * 2):
        for j in range(N - M + 1, N * 2):
            is_right = 0
            for c in range(4):
                is_fail, fits = 0, 0
                key = list(zip(*key[::-1]))
                for k in range(M):
                    for z in range(M):
                        if MAP[i + k][j + z] == 2:
                            continue
                        if MAP[i + k][j + z] == 1 and key[k][z] == 1:
                            is_fail = 1
                            break
                        if MAP[i + k][j + z] == 0 and key[k][z] == 1:
                            fits += 1
                    if is_fail:
                        break
                if not is_fail and fits == cnt:
                    return True    
    
    return False