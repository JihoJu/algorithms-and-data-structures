def solution(cacheSize, cities):
    time = 0    # cnt: cache 에 들어 있는 데이터 수
    cache = dict()
    for city in cities:
        city = city.lower()
        # cache 내 city 정보가 존재
        if city in cache:
            del cache[city]
            time += 1
        # cache 가 꽉 차있는 경우
        elif cacheSize != 0 and len(cache) >= cacheSize:
            del cache[list(cache.keys())[0]]
            time += 5
        else:
            time += 5
        
        if len(cache) < cacheSize:
            cache[city] = 0
            
    return time