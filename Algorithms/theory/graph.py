from queue import Queue

"""
    Graph - bfs, dfs 기초 알고리즘 정리
"""

graph = dict()

graph["A"] = ["B", "C"]
graph["B"] = ["A", "D"]
graph["C"] = ["A", "G", "H", "I"]
graph["D"] = ["B", "E", "F"]
graph["E"] = ["D"]
graph["F"] = ["D"]
graph["G"] = ["C"]
graph["H"] = ["C"]
graph["I"] = ["C", "J"]
graph["J"] = ["I"]


def bfs():
    """ BFS (Breath First Search) (너비 우선 탐색) : 정점들과 같은 레벨에 있는 노드들 (형제 노드)을 먼저 탐색

    :param 으로 graph, start_node 를 받아도 됨

    이 알고리즘은 그래프 노드가 모두 이어져 있지 않다는 것을 전제로 모든 노드 순회
    """

    visited_vertex = list()
    queue = Queue()

    for v in graph:
        queue.put(v)
        while not queue.empty():
            is_visit = queue.get()
            if is_visit not in visited_vertex:
                visited_vertex.append(is_visit)
                for e in graph[is_visit]:
                    queue.put(e)

    for v in visited_vertex:
        print(v)


""" 
    DFS (Depth First Search) (깊이 우선 탐색) : 정점의 자식들을 먼저 탐색
"""

recursive_visited = list()  # dfs 시 방문 노드 담는 리스트


def dfs_recursion(vertex):
    """
        재귀 용법 사용한 dfs
    """
    recursive_visited.append(vertex)

    for v in graph[vertex]:
        if v not in recursive_visited:
            dfs_recursion(v)


def dfs_stack(start_vertex):
    """
        스택을 사용 dfs
    """

    visited = list()
    stack = list()

    stack.insert(0, start_vertex)
    while len(stack) != 0:
        node = stack.pop(0)
        if node not in visited:
            visited.append(node)
            for v in graph[node]:
                stack.insert(0, v)

    for v in visited:
        print(v)
