answer = []

def dfs(i, des):
    if i == len(g_tickets):
        path.append(des)
        answer.append(path.copy())
        path.pop()
    else:
        for j in range(len(g_tickets)):
            if visited[j] == 0 and g_tickets[j][0] == des:
                visited[j] = 1
                path.append(g_tickets[j][0])
                dfs(i + 1, g_tickets[j][1])
                path.pop()
                visited[j] = 0

def solution(tickets):
    global g_tickets, visited, path
    g_tickets = tickets.copy()
    visited = [0 for _ in range(len(tickets))]
    path = []
    
    dfs(0, "ICN")
    answer.sort()
    
    return answer[0]