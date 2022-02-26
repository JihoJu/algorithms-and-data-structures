""" 다익스트라 (Dijkstra) 알고리즘

    필요 저장 공간
    - 거리 저장 배열: 시작 노드 ~ 나머지 모든 노드로 가는 최단 거리를 저장
    - 우선 순위 큐 (MinHeap): 각 인접 노드 간의 거리를 삽입
        필요 이유: 최단 거리를 우선적 계산을 하기 때문에 불필요 계산을 없애기 위함 & 계산 속도 Up!

    - 배운점
        - python 에서 "거리가 있는 graph" 를 표현하기 위해선
            {'A': {'B':5, 'C': 1}, ...} 와 같이 dict 안 정점을 key 로 설정 후 value 에 해당 정점의 인접 정점과 거리를 dict 형태로 구성
        - {vertex: float('inf') for vertex in graph.keys()} => 이런 표현도 있다! (기존에 list 에서만 씀,,,)
        - python 에서 무한대를 표시: float('inf')
        - heapq 라이브러리
"""
import heapq


class MinHeap:
    """ Min Heap """

    def __init__(self):
        self.heap = [0, ]  # index 0: MinHeap (우선 순위 큐) 에 저장된 데이터 개수

    def insert(self, data):
        """ Min Heap 에 데이터 삽입 """

        self.heap.append(data)
        self.heap[0] += 1  # Heap 데이터 개수 update

        if self.heap[0] == 1:  # heap 에 data 가 아예 없을 경우
            return
        else:  # heap 에 데이터 존재
            comp_index = self.heap[0]  # 부모 노드와 비교를 위한 비교 index 로 삽입된 노드의 index (minheap 마지막 index)

            while comp_index > 1:
                p_index = comp_index // 2  # 부노 노드 index
                if data[1] < self.heap[p_index][1]:
                    self.heap[comp_index] = self.heap[p_index]
                else:
                    break
                comp_index = p_index
            self.heap[comp_index] = data

    def pop(self):
        """ Min Heap 에서 가장 작은 데이터 pop """

        if not self.is_empty():  # Heap 이 not empty 경우
            return_data = self.heap[1]

            comp_data = self.heap.pop()  # heap 마지막 data 를 pop
            self.heap[0] -= 1  # heap 의 마지막 데이터 pop 했기에 data 개수 1 다운

            if self.heap[0] == 0:  # heap 의 마지막 데이터 pop 하는 경우
                return return_data

            comp_idx = 2  # comp_data 와 비교할 index 로 root(1) 의 자식 노드를 가리킴
            while comp_idx <= self.heap[0]:

                if (comp_idx < self.heap[0]) and (self.heap[comp_idx][1] > self.heap[comp_idx + 1][1]):
                    comp_idx += 1
                if comp_data[1] <= self.heap[comp_idx][1]:
                    break
                self.heap[comp_idx // 2] = self.heap[comp_idx]

                comp_idx *= 2

            self.heap[comp_idx // 2] = comp_data

        return return_data

    def is_empty(self):
        """ MinHeap 이 비었는 지 check 위함 """

        if self.heap[0] == 0:
            return True

        return False


GRAPH = {
    'A': {'B': 8, 'C': 1, 'D': 2},
    'B': {},
    'C': {'B': 5, 'D': 2},
    'D': {'E': 3, 'F': 5},
    'E': {'F': 1},
    'F': {'A': 5}
}


def dijkstra(start_vertex: str, graph: dict):
    """ Dijkstra Algorithm : 단순 시작 정점에서 모든 정점까지의 최단 거리 구하기

        import heapq    # 파이썬에 저장된 heapq library

        queue = []
        heapq.heappush(queue, [2, 'A'])
        heapq.heappush(queue, [5, 'B'])
        heapq.heappush(queue, [1, 'C'])
        heapq.heappush(queue, [7, 'D'])

        for index in range(len(queue)):
            print(heapq.heappop())

        # 출력: [[1, 'C'], [5,  'B'], [2, 'A'], [7, 'D']]
        # 각 data 맨 앞을 key 로 해서 min heap 을 구성 -> ['C', 1] 처럼 사용 X
    """

    distances = {vertex: float('inf') for vertex in graph.keys()}  # 한 노드에서 각 노드까지 최소 거리를 저장하기 위한 dict
    heap = MinHeap()  # 최소 우선 순위 큐(MinHeap)

    distances[start_vertex] = 0  # 기준이 되는 정점 노드는 자기 자신과 거리가 0 이라 가정
    heap.insert((start_vertex, distances[start_vertex]))  # 우선 순위 큐에 (기준 노드, 0) 삽입

    while not heap.is_empty():  # 우선 순위 큐에 데이터가 없을 때까지 반복
        vertex, distance = heap.pop()  # (node, 거리) 데이터 구조(tuple)로 가장 거리가 최소인 노드 pop

        if distance > distances[vertex]:  # pop 된 정점까지 거리가 distances 에 저장된 거리보다 클 경우
            continue

        for adj_vertex, adj_distance in graph[vertex].items():
            current_distance = adj_distance + distance

            if current_distance < distances[adj_vertex]:
                distances[adj_vertex] = current_distance
                heap.insert((adj_vertex, current_distance))


# GRAPH = {
#     'A': {'B': 8, 'C': 1, 'D': 2},
#     'B': {},
#     'C': {'B': 5, 'D': 2},
#     'D': {'E': 3, 'F': 5},
#     'E': {'F': 1},
#     'F': {'A': 5}
# }

def deep_dijkstra(start: str, end: str, graph: dict):
    """ Dijkstra Algorithm: 시작 정점에서 모든 정점까지 최단 거리 + 시작 정점에서 마지막 정점까지 최단 경로로 가는 정점들 나타내기
    MinHeap: heapq library 사용
    """

    distances = {vertex: [float('inf'), start] for vertex in graph.keys()}  # 'A': [거리, 해당 거리의 인접 정점]
    heap = list()  # 우선 순위 큐: MinHeap

    distances[start][0] = 0
    heapq.heappush(heap, distances[start])  # 우선 순위 큐에 [거리, 해당 거리의 인접 정점] push

    while heap:
        current_distance, current_vertex = heapq.heappop(heap)

        if current_distance > distances[current_vertex][0]:
            continue

        for vertex, distance in graph[current_vertex].items():
            comp_distance = current_distance + distance  # (시작 정점 ~ 현재 정점 거리) + (현재 정점 ~ 인접 정점 거리)

            if comp_distance < distances[vertex][0]:
                distances[vertex] = [comp_distance, current_vertex]
                heapq.heappush(heap, [comp_distance, vertex])

    path = end
    path_out = f"{end} -> "

    while distances[path][1] != start:
        path_out += distances[path][1] + " -> "
        path = distances[path][1]

    path_out += start

    print(path_out)


deep_dijkstra("A", "F", GRAPH)
