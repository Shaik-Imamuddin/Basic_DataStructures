class Node:
    def __init__(self,data):
        self.data = data
        self.addr = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insertatend(self,val):
        newNode = Node(val)

        if self.head is None:
            self.head = newNode
            newNode.addr = self.head
        else:
            temp = self.head
            while temp.addr != self.head:
                temp = temp.addr
            temp.addr = newNode
            newNode.addr = self.head

    def display(self):
        if self.head is None:
            print("List is Empty")
            return

        temp = self.head
        while True:
            print(temp.data,end=" ")
            temp = temp.addr
            if temp == self.head:
                break
        print()


cll = CircularLinkedList()

while True:
    val = int(input())
    if val == -1:
        break
    cll.insertatend(val)
cll.display()