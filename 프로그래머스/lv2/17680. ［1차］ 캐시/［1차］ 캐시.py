from collections import deque

def solution(cacheSize, cities):
    time = 0    # cnt: cache 에 들어 있는 데이터 수
    cache = deque(maxlen=cacheSize)
    
    for city in cities:
        city = city.lower()
        # cache 내 city 정보가 존재
        if city in cache:
            cache.remove(city)
            cache.append(city)
            time += 1
        else:
            cache.append(city)
            time += 5
            
    return time