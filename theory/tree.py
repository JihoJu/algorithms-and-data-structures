import random


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class TreeMgmt:
    """ 이진 탐색 트리 """

    def __init__(self):
        self.head = None

    def insert(self, data):

        if self.head is None:
            self.head = TreeNode(data)
            return

        parent = None
        child = self.head
        while child is not None:
            parent = child
            if data < child.value:
                child = child.left
            elif data > child.value:
                child = child.right
            else:
                is_exist = True  # 해당 노드의 존재를 알려 주기 위함
                break

        if is_exist:
            print("해당 값의 노드가 이미 존재!")
            return

        if data < parent.value:
            parent.left = TreeNode(data)
        else:
            parent.right = TreeNode(data)

    def inorder(self, node: TreeNode):
        if node is None:
            return None

        self.inorder(node.left)
        print(node.value)
        self.inorder(node.right)


tree = TreeMgmt()
input_data = list(random.sample(range(100), 10))
for data in input_data:
    tree.insert(data)

tree.inorder(tree.head)
