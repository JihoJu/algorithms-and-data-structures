# Stack

### Stack(스택)이란

- **데이터의 입출력이 한 곳(방향)으로 제한**이 되어있다.
- 또한, **데이터의 입출력 방향은 Last-in-First-out (LIFO) 로 마지막에 들어온 데이터가 가장 먼저 나오는 데이터 구조**이다.

### **What is it used for?**

- **Call stack of function(recursion)**
- **Operator postfix notation**
- **스트링을 파라미터로 받아서, 그것을 역순으로 리턴하는 함수**
- etc…

### Implementation

Stack 에는 기본적으로 **4가지의 추상화된 함수**가 존재

- **push**: 데이터를 넣는다.
- **pop**: 스택에 있는 최상위 값을 뺀다.
- **isFull**: stack 꽉차있는 지 확인
- **isEmpty**: 스택이 비어있있는 지 확인

> **왜 isEmpty 같은 함수가 필요한거지??**
> 
- **for (i in 0 until stack.size)** 로도 구현이 괜찮지 않나?
    - 아니다. loop 를 돌리기 위해서 새로운 변수 i 를 생성하고 stack 의 size도 확인을 해야한다.
- 이를 효율적으로 수정하면 다음과 같다.
- **while(!stack.isEmpty)**
    - isEmpty 함수를 사용하면 마지막 데이터의 위치를 가리키는 ‘stack pointer’ 만 확인하면 결과가 리턴이 되어 **for (i in 0 until stack.size)** 보다 효율적이다.

**Abstract Data Type 인 Stack 을 구현하는 방법**에는 여러가지가 존재

- Array
    - **마지막에 들어온 데이터의 위치를 표시하는 ‘Stack Pointer(sp)’ 가 필요**
        - Last index 를 tracking
    - 데이터 크기를 미리 지정해야하는 단점
- LinkedList
    - 마지막에 들어온 노드(데이터)의 위치를 tracking 할 수 있는 **‘Stack Pointer(sp)’ 이 또한 필요**
- Queue
    - **Queue Data Structure 2개로도 Stack 을 구현 가능**
    - Stack Pointer 가 필요가 없다.

# Queue

### Queue(큐) 란

- **데이터의 입력과 출력이 각각 한 곳(방향)으로 제한**이 되어있다.
    - **입력**은 큐의 **마지막**에서 이루어진다.
    - 출력은 큐의 **앞단**에서 이루어진다.
- **데이터의 입출력 방향은 First-in-First-out (FIFO) 으로 처음에 들어온 데이터가 가장 먼저 나오는 데이터 구조**이다.

### What is it used for?

- **컴퓨터 운영체제의 테스크 스케줄링**
- etc…

### Implementation

Queue 에는 기본적으로 5**가지의 추상화된 함수**가 존재

- **enQueue()**: 큐에 데이터를 넣는다.
- **deQueue()**: 큐에서 데이터를 빼낸다.
- **isEmpty()**: 큐가 비어있는지 확인한다.
- **isFull()**: 큐가 꽉 차 있는지 확인한다.
- **peek()**: 앞에있는 원소를 삭제하지 않고 반환한다.

**Abstract Data Type 인 Queue 를 구현하는 방법**에는 여러가지가 존재

- Array
    - Queue의 처음과 마지막 위치(인덱스)의 tracking **변수 필요**
        - Front, Back index 를 tracking
- LinkedList
    - Queue의 처음과 마지막 위치를 tracking **포인터 변수 필요**
- Stack
    - Stack **2개로 Queue 구현 가능**

### Problem

데이터를 빼내는 deQueue() 연산을 사용하면 맨 앞(front)에 있는 데이터가 빠져나간다. 그럼 **맨 앞 이후에 있는 데이터들을 앞으로 한 칸씩 이동**해야한다. 그렇지 않으면 **Queue의 가동 범위가 줄어들고, 재사용이 불가**해진다.

이러한 문제점 보완하기 위해 **원형 큐(Circle Queue)** 를 사용 혹은 **재할당 과정**을 거친다.

<hr>

## Conclusion
**Stack** 과 **Queue** 는
- 데이터 삽입은 한 방향으로 제한이 되어 있기에 O(1)인 시간 복잡도를 갖는다.
- 데이터 삭제(출력) 또한 한 방향에서 이루어져 O(1)의 시작 복잡도를 갖는다.

그렇기에 특정 위치에 값을 삽입, 특정 값 삭제와 같은 연산이 아닌 s**tack, queue의 특정 규칙(패턴)을 갖는 상황에 해당 data structure 를 적용하면 더욱 효울적으로 
데이터를 관리할 수 있을 뿐만 아니라 데이터 흐름을 통제**할 수 있다.
