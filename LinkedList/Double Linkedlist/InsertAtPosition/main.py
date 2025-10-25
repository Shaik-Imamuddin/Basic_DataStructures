class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insertAtEnd(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:  
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def insertAtPosition(self, val, pos):
        new_node = Node(val)

        if pos == 1:
            new_node.next = self.head
            if self.head:
                self.head.prev = new_node
            self.head = new_node
            return

        temp = self.head
        count = 1
        while temp is not None and count < pos - 1:
            temp = temp.next
            count += 1

        if temp is None:
            print("Position out of bounds")
            return

        new_node.next = temp.next
        new_node.prev = temp
        if temp.next:
            temp.next.prev = new_node
        temp.next = new_node

    def displayForward(self):
        if self.head is None:
            print("List is Empty")
            return
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    def displayBackward(self):
        if self.head is None:
            print("List is Empty")
            return
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        while temp is not None: 
            print(temp.data, end=" ")
            temp = temp.prev
        print()

dll = DoublyLinkedList()

while True:
    val = int(input())
    if val == -1:
        break
    dll.insertAtEnd(val)
val = int(input())
pos = int(input())
dll.insertAtPosition(val, pos)

dll.displayForward()
dll.displayBackward()
