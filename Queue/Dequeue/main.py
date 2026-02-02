class Node:
    def __init__(self,val):
        self.data=val
        self.prev=None
        self.next=None

front=None
rear=None

def insertFront(val):
    global front,rear
    newNode=Node(val)
    newNode.next=front

    if front is None:
        rear=newNode
    else:
        front.prev=newNode

    front=newNode

def insertRear(val):
    global front,rear
    newNode=Node(val)
    newNode.prev=rear

    if rear is None:
        front=newNode
    else:
        rear.next=newNode

    rear=newNode

def deleteFront():
    global front,rear
    if front is None:
        print("Dequeue Underflow")
        return

    front=front.next

    if front is None:
        rear=None
    else:
        front.prev=None

def deleteRear():
    global front,rear
    if rear is None:
        print("Dequeue Underflow")
        return

    rear=rear.prev

    if rear is None:
        front=None
    else:
        rear.next=None

def display():
    if front is None:
        print("Dequeue is Empty")
        return

    temp=front
    while temp:
        print(temp.data,end=" ")
        temp=temp.next
    print()

while True:
    val=int(input())
    if val==-1:
        break
    if val%2==0:
        insertRear(val)
    else:
        insertFront(val)

display()
deleteFront()
deleteRear()
display()