class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None

class Linkedlist:
    def __init__(self):
        self.head=None

    def insertatend(self,val):
        newNode=Node(val)

        if self.head is None:
            self.head=newNode
        else:
            temp = self.head
            while temp.addr is not None:
                temp=temp.addr
            temp.addr=newNode
            
    def display(self):
        if self.head is None:
            print("Linkedlist is Empty")
        temp=self.head
        while temp is not None:
            print(temp.data,end=" ")
            temp=temp.addr

ll=Linkedlist()
val=0

while(val!=-1):
    val=int(input())
    if(val!=-1):
        ll.insertatend(val)
ll.display()