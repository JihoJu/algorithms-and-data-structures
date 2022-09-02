def solution(queue1, queue2):
    q_sum = sum(queue1)  # 큐1 합
    same = (q_sum + sum(queue2)) // 2 # 두 큐의 크기가 같은 값
    
    queue1.extend(queue2)   # 투 포인터를 위한 두 큐 합치기
    # 투 포인터를 위한 두 큐의 시작, 끝 인덱스 설정
    s1, e1, s2, e2 = 0, len(queue2) - 1, len(queue2), len(queue1) - 1
    
    cnt = 0 # 연산 횟수
    size = len(queue1)  # 큐1 사이즈 
    for _ in range(len(queue2) * 4):
        if q_sum == same:
            return cnt
        elif q_sum < same:
            e1 = (e1 + 1) % size
            s2 = (s2 + 1) % size
            q_sum += queue1[e1]
        elif q_sum > same:
            q_sum -= queue1[s1]
            e2 = (e2 + 1) % size
            s1 = (s1 + 1) % size
        # 큐가 원래의 모습으로 돌아온 경우
        if s1 == 0 and e1 == len(queue2) - 1:
            break
        cnt += 1
        
    return -1