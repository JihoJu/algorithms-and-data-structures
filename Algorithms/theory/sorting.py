import random


class Sorter:
    """ An object that sorts the numbers in a list in ascending order """

    def __init__(self):
        self.input_data = list(random.sample(range(100), 13))
        # self.input_data = [45, 93, 8, 7, 1, 27, 80, 11, 13, 65]
        self.sorted_list = None

    def bubble_sort(self):
        """ 버블 정렬 (오름 차순)"""

        idx_list = len(self.input_data) - 1

        for i in range(idx_list, 0, -1):
            for j in range(0, i):
                if self.input_data[j] > self.input_data[j + 1]:
                    self.input_data[j], self.input_data[j + 1] = self.input_data[j + 1], self.input_data[j]

        """ 다른 풀이
        for index in range(len(self.input_data) - 1):
            swap = False  # 한 번 리스트 를 돌 때 다 정렬이 되어있는지 아닌지 확인 변수
            for index2 in range(len(self.input_data) - i - 1):
                if self.input_data[index2] > self.input_data[index2 + 1]:
                    self.input_data[index2], self.input_data[index2 + 1] = self.input_data[index2 + 1], self.input_data[
                        index2]
                    swap = True
            if swap is False:  # 현재 리스트에 데이터가 모두 정렬이 되어 있는 경우
                break
        """

        self.sorted_list = self.input_data

    def selection_sort(self):
        """ 선택 정렬 (오름 차순) """

        idx_list = len(self.input_data)

        for i in range(0, idx_list - 1):
            idx_min = i
            for j in range(i + 1, idx_list):
                if self.input_data[j] < self.input_data[idx_min]:
                    idx_min = j
            if idx_min != i:
                self.input_data[i], self.input_data[idx_min] = self.input_data[idx_min], self.input_data[i]

        self.sorted_list = self.input_data

    def insertion_sort(self):
        """ 삽입 정렬 (오름 차순) """

        idx_list = len(self.input_data)

        for i in range(1, idx_list):
            tmp = self.input_data[i]
            j = i - 1
            while (j >= 0) and (self.input_data[j] > tmp):
                self.input_data[j + 1] = self.input_data[j]
                j = j - 1

            if (j + 1) != i:
                self.input_data[j + 1] = tmp

        self.sorted_list = self.input_data

    def quick_sort(self, input_list):
        """ 퀵 정렬 (오름 차순) -> 처음에 직접 바로 짠 코드 """

        if len(input_list) <= 1:
            return input_list

        sorted_list = list()

        pivot = input_list[0]
        left_list = list()
        right_list = list()
        for element in input_list[1:]:
            if element <= pivot:
                left_list.append(element)
            else:
                right_list.append(element)

        if len(left_list) >= 1:
            sorted_list = self.quick_sort(left_list)
        sorted_list.append(pivot)
        if len(right_list) >= 1:
            sorted_list.extend(self.quick_sort(right_list))

        return sorted_list

    def qsort(self, data):
        """ 다시 생각 후 짠 코드 """

        if len(data) <= 1:
            return data

        left, right = list(), list()
        pivot = data[0]

        for item in data[1:]:
            if item <= pivot:
                left.append(item)
            else:
                right.append(item)

        return self.qsort(left) + [pivot] + self.qsort(right)

    def merge_sort(self, input_list):
        """ 합병 정렬 (오름 차순) """

        if len(input_list) <= 1:
            return input_list

        divide_index = len(input_list) // 2
        list1 = input_list[:divide_index]
        list2 = input_list[divide_index:]

        return self.merge(self.merge_sort(list1), self.merge_sort(list2))

    def merge(self, list1, list2):
        """ 두 리스트 (오름 차순) 순서에 맞게 합치기 """

        sorted_list = list()

        index1, index2 = 0, 0
        while index1 < len(list1) and index2 < len(list2):
            if list1[index1] <= list2[index2]:
                sorted_list.append(list1[index1])
                index1 += 1
            else:
                sorted_list.append(list2[index2])
                index2 += 1

        for i in range(index1, len(list1)):
            sorted_list.append(list1[i])
        for i in range(index2, len(list2)):
            sorted_list.append(list2[i])

        return sorted_list
