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
            
    def deleteFromPosition(self, pos):
        if self.head is None:
            print("LinkedList is Empty")
            return

        if pos <= 0:
            print("Invalid Position")
            return

        if pos == 1:
            temp = self.head
            self.head = self.head.addr
            print(f"{temp.data} is Deleted")
            return

        temp = self.head
        prev = None

        for i in range(1, pos):
            prev = temp
            temp = temp.addr
            if temp is None:
                print("Position out of Range")
                return

        prev.addr = temp.addr
        print(f"{temp.data} is Deleted")
 
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
pos=int(input())
ll.deleteFromPosition(pos)
ll.display()