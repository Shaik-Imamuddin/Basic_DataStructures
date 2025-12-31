class Node:
    def __init__(self,data):
        self.data=data
        self.addr=None

class Queue:
    def __init__(self):
        self.front=None
        self.rear=None

    def enqueue(self,val):
        newNode=Node(val)
        if self.front is None:
            self.front=self.rear=newNode
            self.rear.addr=self.front
        else:
            self.rear.addr=newNode
            self.rear=newNode
            self.rear.addr=self.front

    def dequeue(self):
        if self.front is None:
            print("Queue Underflow!")
            return
        if self.front==self.rear:
            print(self.front.data)
            self.front=self.rear=None
        else:
            print(self.front.data)
            self.front=self.front.addr
            self.rear.addr=self.front

    def peek(self):
        if self.front is None:
            print("Queue is empty!")
            return
        print("Front element:",self.front.data)

    def display(self):
        if self.front is None:
            print("Queue is empty!")
            return
        temp=self.front
        while True:
            print(temp.data,end=" ")
            temp=temp.addr
            if temp==self.front:
                break
        print()

q=Queue()
while True:
    val=int(input())
    if val==-1:
        break
    q.enqueue(val)

q.display()
q.dequeue()
q.peek()
q.display()