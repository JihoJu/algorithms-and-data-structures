import ast


def swap(a, b):
    a = 123
    b = 11
    print(id(a))
    print(id(b))


word_1 = "programming"
a = 1234
word_2 = "programming"
b = 1234
print(id(word_1))
print(id(word_2))
print(id("programming"))
print("a : ", id(a))
print("b : ", id(b))
swap(a, b)
print(id(a), id(b))
# print(word_1 is word_2)

# diction = dict()

# diction["good"] = 1
# diction["best"] = 2
# diction["parse"] = 3

# print(id(diction))
# aaaa(diction)
# print(diction["good"])
