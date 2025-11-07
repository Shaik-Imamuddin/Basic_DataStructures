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

    def deleteFromPosition(self, pos):
        if self.head is None:
            print("LinkedList is Empty")
            return

        if pos == 1:  
            self.deleteFromBeginning()
            return

        temp = self.head
        count = 1
        while temp is not None and count < pos:
            temp = temp.next
            count += 1

        if temp is None:
            print("Position out of range")
            return

        if temp.next is not None:  
            temp.next.prev = temp.prev
        if temp.prev is not None:  
            temp.prev.next = temp.next

    def displayForward(self):
        if self.head is None:
            print("Linkedlist is Empty")
            return
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    def displayBackward(self):
        if self.head is None:
            print("Linkedlist is Empty")
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
    if val==-1:
        break
    dll.insertAtEnd(val)
pos = int(input())
dll.deleteFromPosition(pos)
dll.displayForward()
dll.displayBackward()