class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insertAtEnd(self, val):
        new_node = Node(val)

        if self.head is None:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            temp = self.head.prev  

            new_node.next = self.head
            new_node.prev = temp

            temp.next = new_node
            self.head.prev = new_node

    def display_forward(self):
        if self.head is None:
            print("List is Empty")
            return

        temp = self.head
        while temp.next != self.head:
            print(temp.data, end=" ")
            temp = temp.next
        print(temp.data)

    def display_backward(self):
        if self.head is None:
            print("List is Empty")
            return

        temp = self.head.prev  

        while temp != self.head:
            print(temp.data, end=" ")
            temp = temp.prev
        print(self.head.data)


ll = LinkedList()

while True:   
    val=int(input())
    if val==-1:
        break
    ll.insertAtEnd(val)

ll.display_forward()
ll.display_backward()