def check(word1, word2):
    index = -1
    n = len(word1)  # 문자 길이
    
    for i in range(n):
        if word1[i] != word2[i]:
            if index == -1:
                index = i
            else:
                return -1
    
    return index

def dfs(begin, cnt):
    global g_target, min_value
    
    if begin == g_target:
        min_value = min(min_value, cnt)
        return
    
    for i, word in enumerate(_words):
        index = check(begin, word)
        if visited[i] == 0 and index != -1:
            visited[i] = 1
            dfs(word, cnt + 1)
            visited[i] = 0
            
def solution(begin, target, words):
    if target not in words:
        return 0
    
    global visited, _words, g_target, min_value
    min_value = float('inf')
    g_target = target
    _words = words.copy()
    visited = [0 for _ in range(len(words))]
    dfs(begin, 0)
    
    return min_value