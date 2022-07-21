# 1. Selection Sorting (선택 정렬) 란?

- 다음과 같은 순서를 반복하며 정렬하는 알고리즘
    1. 주어진 데이터 중, 최소값을 찾음
    2. 해당 최소값을 데이터 맨 앞에 위치한 값과 교체함
    3. 맨 앞의 위치를 뺀 나머지 데이터를 동일한 방법으로 반복
- **[https://visualgo.net/en/sorting](https://visualgo.net/en/sorting)**

```python
def selection_sort(data):
    for stand in range(len(data) - 1):
        lowest = stand
        for index in range(stand + 1, len(data)):
            if data[lowest] > data[index]:
                lowest = index
        data[lowest], data[stand] = data[stand], data[lowest]
    return data
```

### Selection sort 시간 복잡도

- 선택 정렬은 반복문이 2개 이므로 시간 복잡도는 O(n^2) 이며, 실제로 상세히 계산하면 n * (n-1) / 2 이다.

# Bubble Sort (버블 정렬) 란?

• 두 인접한 데이터를 비교해서, 앞에 있는 데이터가 뒤에 있는 데이터보다 크면, 자리를 바꾸는 정렬 알고리즘

### 버블 정렬 구현

- n개의 리스트가 있는 경우 최대 n-1번의 로직을 적용한다.
- 로직을 1번 적용할 때마다 가장 큰 숫자가 뒤에서부터 1개씩 결정
- 로직이 경우에 따라 일찍 끝날 수도 있다. 따라서 로직을 적용할 때 한 번도 데이터가 교환된 적이 없다면 이미 정렬된 상태이므로 더 이상 로직을 반복 적용할 필요가 없다.

```python
def bubblesort(data):
    for index in range(len(data) - 1):
        swap = False
        for index2 in range(len(data) - index - 1):
            if data[index2] > data[index2 + 1]:
                data[index2], data[index2 + 1] = data[index2 + 1], data[index2]
                swap = True
        
        if swap == False:
            break
    return data
```

### 버블 정렬 시간 복잡도

- 반복문이 두 개이므로 O(n^2) 의 시간 복잡도를 갖는다.
- 최악의 경우: n * (n - 1) / 2
- 완전 정렬이 되어 있는 경우: O (n)

# Insertion sort (삽입 정렬) 란?

- 삽입 정렬은 두 번째 인덱스부터 시작
- 해당 인덱스(key 값) 앞에 있는 데이터(B)부터 비교해서 key 값이 더 작으면, B값을 뒤 인덱스로 복사
- 이를 key 값이 더 큰 데이터를 만날때까지 반복, 그리고 큰 데이터를 만난 위치 바로 뒤에 key 값을 이동

## Insertion sort 구현

```python
def insertion_sort(data):
    for index in range(len(data) - 1):
        for index2 in range(index + 1, 0, -1):
            if data[index2] < data[index2 - 1]:
                data[index2], data[index2 - 1] = data[index2 - 1], data[index2]
            else:
                break
    return data
```

### 버블 정렬 시간 복잡도

- 반복문이 두 개이므로 O(n^2) 의 시간 복잡도를 갖는다.
- 최악의 경우: n * (n - 1) / 2
- 완전 정렬이 되어 있는 경우: O (n)