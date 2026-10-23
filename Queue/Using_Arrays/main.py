class Queue:
    def __init__(self, n):
        self.queue = [0] * n
        self.front = -1
        self.rear = -1
        self.n = n
        self.count = 0

    def isEmpty(self):
        return self.count == 0

    def isFull(self):
        return self.count == self.n

    def enqueue(self, x):
        if self.isFull():
            print("Queue is Full!")
            return

        if self.isEmpty():
            self.front = 0
            self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.n

        self.queue[self.rear] = x
        self.count += 1

    def dequeue(self):
        if self.isEmpty():
            print("Queue is Empty!")
            return -1

        x = self.queue[self.front]

        if self.count == 1:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.n

        self.count -= 1
        return x

    def getFront(self):
        if self.isEmpty():
            print("Queue is Empty!")
            return -1
        return self.queue[self.front]

    def getRear(self):
        if self.isEmpty():
            print("Queue is Empty!")
            return -1
        return self.queue[self.rear]

    def display(self):
        if self.isEmpty():
            print("Queue is Empty!")
            return

        for i in range(self.front, self.rear + 1):
            print(self.queue[i], end=" ")
        print()


q = Queue(100)


while True:
    val = int(input())
    if val==-1:
        break
    q.enqueue(val)

q.display()

print(q.isEmpty())
print(q.isFull())

print(q.getFront())
print(q.getRear())

print(q.dequeue())
q.display()

print(q.getFront())
print(q.getRear())