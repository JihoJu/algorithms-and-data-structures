from collections import deque


def get_distance(r1, c1, r2, c2):
    return abs(r1 - r2) + abs(c1 - c2)


def check(r1, c1, r2, c2):
    if r1 == r2:  # 같은 행
        if abs(c1 - c2) < 2:
            return False
        else:
            if place[r1][(c1 + c2) // 2] == "X":
                return True
            else:
                return False
    elif c1 == c2:  # 같은 열
        if abs(r1 - r2) < 2:
            return False
        else:
            if place[(r1 + r2) // 2][c1] == "X":
                return True
            else:
                return False
    else:
        d_x1, d_y1, d_x2, d_y2 = r1, c2, r2, c1
        if place[d_x1][d_y1] == "X" and place[d_x2][d_y2] == "X":
            return True
        else:
            return False

def solution(places):
    answer = []

    dx = [0, 0, -1, 1]  # 좌우상하
    dy = [-1, 1, 0, 0]

    global place
    for place in places:
        # P 위치 담기
        pos = [
            (row, col) for row in range(5) for col in range(5) if place[row][col] == "P"
        ]
        result = 1  # 거리두기 결과
        for x, y in pos:
            visited = [[0 for _ in range(5)] for _ in range(5)]  # 방문 여부
            dq = deque()
            dq.append((x, y))  # P 위치 추가
            visited[x][y] = 1
            while len(dq) != 0:
                px, py = dq.popleft()
                for i in range(4):
                    mx = px + dx[i]
                    my = py + dy[i]
                    if (
                        0 <= mx < 5
                        and 0 <= my < 5
                        and visited[mx][my] == 0
                        and get_distance(x, y, mx, my) <= 2
                    ):
                        if place[mx][my] == "P":
                            if not check(x, y, mx, my):
                                result = 0
                                break
                        visited[mx][my] = 1
                        dq.append((mx, my))
                # 거리두기가 안지켜졌을 경우
                if result == 0:
                    break
            if result == 0:
                break
        answer.append(result)

    return answer
