class QueueArray:
    def __init__(self):
        self.queue=[]
    
    def enqueue(self,val):
        self.queue.append(val)
    
    def dequeue(self):
        if len(self.queue)==0:
            print("Queue Underflow!")
            return
        print(self.queue.pop(0))
    
    def peek(self):
        if len(self.queue)==0:
            print("Queue is empty!")
            return
        print("Front element:",self.queue[0])
    
    def display(self):
        if len(self.queue)==0:
            print("Queue is empty!")
            return
        print(*self.queue)

q=QueueArray()
while True:
    val=int(input())
    if val==-1:
        break
    q.enqueue(val)

q.display()
q.dequeue()
q.peek()
q.display()
