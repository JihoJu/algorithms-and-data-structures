""" Minimum Spanning Tree (MST)
    - Spanning Tree(신장 트리): 기존 그래프의 모든 노드가 연결되어 있으며 트리의 속성을 만족하는 그래프 (사이클 X)
    - MST(최소 신장 트리): 신장 트리를 만족하며 가중치가 최소인 간선으로 이루어진 그래프
    - 관련 알고리즘
        - Kruskal Algorithm
        - Prim Algorithm
    - 사용 알고리즘: Union-Find 알고리즘
    - Union-Find 기법: Disjoint Set(서로소 집합)을 표현할 때 사용하는 알고리즘 -> 트리 구조를 형성할 때 사이클이 형성되는지 확인
        - Union: 두 개별 집합을 합침
        - Find: 현재 두 원소가 같은 집합에 있는 지 확인
        - 시간 복잡도: O(N) -> 이를 해결하기 위한 방법: union-by-rank 기법, path compression 기법
            - Union-by-rank 기법: 트리에서 각 노드의 rank (높이)를 기억해두고 union 시 rank 가 큰 트리에 union
            - Path compression 기법: Find를 실행한 노드에서 거쳐간 노드를 루트에 다이렉트로 연결하는 기법
            - 위 2가지 방법을 사용하게 되면 union-find 알고리즘 시간 복잡도를 O(N) -> O(logN) 으로 대폭 줄일 수 있다.
"""

mygraph = {
    'vertex': ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
    'edges': [(7, 'A', 'B'), (5, 'A', 'D'), (8, 'B', 'C'), (9, 'B', 'D'), (7, 'B', 'E'), (5, 'C', 'E'), (7, 'D', 'E'),
              (6, 'D', 'F'), (8, 'E', 'F'), (9, 'E', 'G'), (11, 'F', 'G')]
}

parent = {key: key for key in mygraph['vertex']}  # 부모 노드
rank = {key: 0 for key in mygraph['vertex']}  # 노드가 어느 높이에 있는 지 확인


def union(v, u):
    """ Union Algorithm: union-by-rank 기법 사용 """

    root1 = find(v)
    root2 = find(u)

    if rank[root1] > rank[root2]:
        parent[root2] = root1
    elif rank[root1] < rank[root2]:
        parent[root1] = root2
    else:
        parent[root2] = root1
        rank[root2] += 1


def find(vertex: str):
    """ Find Algorithm: path compression 사용 """

    if parent[vertex] != vertex:
        parent[vertex] = find(parent[vertex])
    return parent[vertex]


def kruskal(graph: dict):
    """ Kruskal Algorithm """

    selected_vertex = set()  # 선택된 정점
    selected_edges = list()  # 선택된 간선

    sorted_edges = sorted(graph['edges'], key=lambda x: x[0])  # 간선 가중치 오름차순 정렬

    while len(selected_vertex) < 7:  # 모든 정점들이 선택될 때까지 반복
        weight, node_v, node_u = sorted_edges.pop(0)

        root1 = find(node_v)
        root2 = find(node_u)

        if root1 == root2:  # Cycle 생기는 경우
            continue

        union(node_v, node_u)
        selected_vertex.add(node_v)
        selected_vertex.add(node_u)
        selected_edges.append((weight, node_v, node_u))

    print(selected_edges)


kruskal(mygraph)
