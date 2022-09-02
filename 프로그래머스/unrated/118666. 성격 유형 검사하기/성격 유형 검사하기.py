def get_indicators(s):
    """ 어떤 지표에 속하는 지 """
    
    if s in "RT":
        return 1
    elif s in "CF":
        return 2
    elif s in "JM":
        return 3
    elif s in "AN":
        return 4

def insert(infos, stype, score):
    """ infos dict 에 검사 정보 삽입 """
    infos[get_indicators(stype)][stype] += score
        
def solution(survey, choices):
    infos = {
        1 : {'R': 0, 'T': 0},
        2 : {'C': 0, 'F': 0},
        3 : {'J': 0, 'M': 0},
        4 : {'A': 0, 'N': 0}
    }
    
    for surv, choi in zip(survey, choices):
        score = choi - 4
        if score < 0:
            insert(infos, surv[0], -1 * score)
        elif score > 0:
            insert(infos, surv[1], score)
    
    result = [] # 각 지표 검사 결과
    for info in infos.values():
        indic = list(info.items())  # 각 지표별 정보
        if indic[0][1] >= indic[1][1]:
            result.append(indic[0][0])
        else:
            result.append(indic[1][0])
    
    answer = ''.join(result)
    
    return answer