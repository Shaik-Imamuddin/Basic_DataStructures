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

    def deleteFromBeginning(self):
        if self.head is None:
            print("Linkedlist is Empty")
            return

        if self.head.next is None: 
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None  

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

dll.deleteFromBeginning()
dll.displayForward()
dll.displayBackward()