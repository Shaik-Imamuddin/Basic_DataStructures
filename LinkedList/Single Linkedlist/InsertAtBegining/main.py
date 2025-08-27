class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None

class Linkedlist:
    def __init__(self):
        self.head=None

    def insertatbegining(self,val):
        newNode = Node(val)
        newNode.addr = self.head
        self.head = newNode

    def display(self):
        if self.head is None:
            print("List is empty")
        temp = self.head
        while temp is not None:
            print(temp.data,end=" ")
            temp=temp.addr
            
ll=Linkedlist()
val=0
while(val!=-1):
    val=int(input())
    if(val!=-1):
        ll.insertatbegining(val)
ll.display()