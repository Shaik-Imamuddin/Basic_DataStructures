class Node:
    def __init__(self,val):
        self.data = val
        self.addr = None
class Linkeslist:
    def __init__(self):
        self.head = None
    def insertAtEnd(self,val):
        newNode = Node(val)

        if self.head is None:
            self.head = newNode
        else:
            temp = self.head
            while temp.addr is not None:
                temp = temp.addr
            temp.addr = newNode

    def insertAtPosition(self,val,pos):
        newNode = Node(val)

        if(pos == 1):
            newNode.addr = self.head
            self.head = newNode
            return
        
        temp = self.head
        count=1

        while temp is not None and count < pos - 1:
            temp = temp.addr
            count+=1
        if temp is None:
            print("Position out of Bounds")
            return
        newNode.addr = temp.addr
        temp.addr = newNode

    def display(self):
        temp = self.head
        if(self.head == None):
            print("LinkedList is Empty")
        while temp is not None:
            print(temp.data,end=" ")
            temp = temp.addr
            
ll=Linkeslist()
val=0

while(val!=-1):
    val = int(input())
    if(val!=-1):
        ll.insertAtEnd(val)
val1 = int(input())
pos = int(input())

ll.insertAtPosition(val1,pos)
ll.display()