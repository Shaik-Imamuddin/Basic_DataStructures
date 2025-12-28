class Node:
    def __init__(self, val):
        self.data = val
        self.addr = None

front = None
rear = None

def enqueue(val):
    global front, rear
    newNode = Node(val)
    if rear is None:
        front = rear = newNode
    else:
        rear.addr = newNode
        rear = newNode

def dequeue():
    global front, rear
    if front is None:
        print("Queue Underflow!")
        return
    print(front.data)
    front = front.addr
    if front is None:
        rear = None

def peek():
    if front is None:
        print("Queue is empty!")
        return
    print("Front element:", front.data)

def display():
    if front is None:
        print("Queue is empty!")
        return
    temp = front
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.addr
    print()

while True:
    val = int(input())
    if val == -1:
        break
    enqueue(val)

display()
dequeue()
peek()
display()