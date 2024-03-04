class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def populate(self, values):
        for value in values:
            new_node = Node(value)
            if self.head is None:
                self.head = new_node
            else:
                current = self.head
                while current.next is not None:
                    current = current.next
                current.next = new_node

    def iterate(self):
        current = self.head
        while current is not None:
            print(current.data)
            current = current.next


