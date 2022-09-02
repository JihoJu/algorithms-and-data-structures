def solution(survey, choices):
    infos = {"RT": 0, "CF": 0, "JM": 0, "AN": 0}
    
    for surv, score in zip(survey, choices):
        if surv not in infos:
            surv = surv[::-1]
            infos[surv] -= (4 - score)
        else:
            infos[surv] += (4 - score)
    
    answer = ''
    for stype, score in infos.items():
        if score >= 0:
            answer += stype[0]
        else:
            answer += stype[1]
    
    return answer