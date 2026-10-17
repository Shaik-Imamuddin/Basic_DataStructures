
class Node:
    def __init__(self, val):
        self.data = val
        self.addr = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, val):
        newNode = Node(val)

        if self.rear is None:
            self.front = self.rear = newNode
        else:
            self.rear.addr = newNode
            self.rear = newNode

    def dequeue(self):
        if self.front is None:
            print("Queue Underflow!")
            return

        print(self.front.data)
        self.front = self.front.addr

        if self.front is None:
            self.rear = None

    def peek(self):
        if self.front is None:
            print("Queue is empty!")
            return

        print("Front element:", self.front.data)

    def display(self):
        if self.front is None:
            print("Queue is empty!")
            return

        temp = self.front

        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.addr
        print()


q = Queue()

while True:
    val = int(input())
    if val == -1:
        break
    q.enqueue(val)

q.display()
q.dequeue()
q.peek()
q.display()