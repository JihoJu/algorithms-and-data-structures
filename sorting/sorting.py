import random


class Sorter:
    """ An object that sorts the numbers in a list in ascending order """

    def __init__(self):
        self.input_data = list(random.sample(range(100), 50))
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
