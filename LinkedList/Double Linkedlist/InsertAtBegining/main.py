class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, val):
        new_node = Node(val)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node

    def display_forward(self):
        if self.head is None:
            print("List is Empty")
            return
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    def display_backward(self):
        if self.head is None:
            print("List is Empty")
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        while temp:
            print(temp.data, end=" ")
            temp = temp.prev
        print()


dll = DoublyLinkedList()
while True:
    val = int(input())
    if val == -1:
        break
    dll.insert_at_beginning(val)

dll.display_forward()
dll.display_backward()