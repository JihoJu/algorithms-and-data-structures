def solution(record):
    answer = []
    
    printer = {"Enter": "님이 들어왔습니다.", "Leave": "님이 나갔습니다."}
    users = dict()
    
    for r in record:
        ar = r.split(' ')
        if ar[0] != "Leave":
            users[ar[1]] = ar[2]
    
    for r in record:
        ar = r.split(' ')
        if ar[0] in printer:
            answer.append(f"{users[ar[1]]}" + printer[ar[0]])
        
    return answer