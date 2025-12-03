class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None

class Stack:
    def __init__(self):
        self.top=None

    def push(self,val):
        newNode=Node(val)
        newNode.addr=self.top
        self.top=newNode

    def pop(self):
        if self.top==None:
            print("Stack Underflow!")
            return
        print(self.top.data)
        self.top=self.top.addr

    def peek(self):
        if self.top==None:
            print("Stack is empty!")
            return
        print("Top element:",self.top.data)

    def display(self):
        if self.top==None:
            print("Stack is empty!")
            return
        temp=self.top
        while temp!=None:
            print(temp.data,end=" ")
            temp=temp.addr
        print()

s=Stack()
while True:
    val=int(input())
    if val==-1:
        break
    s.push(val)

s.display()
s.pop()
s.peek()
s.display()