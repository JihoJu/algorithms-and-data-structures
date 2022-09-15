def solution(n, words):
    answer = []
    
    exc_words = set()
    turn = 0
    last = words[0][0]
    for i, word in enumerate(words):
        num = (i % n) + 1
        if num == 1:
            turn += 1
        if word[0] != last or word in exc_words:
            return [num, turn]
        exc_words.add(word)
        last = word[-1]

    return [0, 0]