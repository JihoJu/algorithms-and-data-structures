dictionary = ['A', 'B', 'C']
def solution(msg):
    answer = []
    
    dic = {chr(i + ord('A')): i + 1 for i in range(0, 26)}  # 사전
    
    i, word, num = 0, "", 27
    while i < len(msg):
        word += msg[i]
        next_i = i + 1
        while word in dic:
            if next_i >= len(msg):
                answer.append(dic[word])
                return answer
            word += msg[next_i]
            next_i += 1
        dic[word] = num
        num += 1
        answer.append(dic[word[:-1]])
        i = next_i - 1
        word = ""
    
    return answer