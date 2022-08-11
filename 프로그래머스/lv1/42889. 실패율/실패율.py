def solution(N, stages):
    fails = [0 for _ in range(N + 1)]  # 스테이지마다 실패 유저 수 표시 (스테이지 - 1 = index)
    fail_rates = dict()
    
    for stage in stages:
        fails[stage - 1] += 1
    
    total = len(stages) # 총 유저 수
    for stage in range(N):
        if total != 0:
            fail_rates[stage + 1] = float(fails[stage]) / total
            total -= fails[stage]
        else:
            fail_rates[stage + 1] = 0.0

    answer = sorted(fail_rates.keys(), key=lambda x: fail_rates[x], reverse=True)
    
    return answer