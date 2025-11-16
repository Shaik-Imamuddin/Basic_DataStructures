class Stack:
    SIZE = 100

    def __init__(self):
        self.arr = [0] * self.SIZE
        self.top = -1

    def is_empty(self):
        return self.top < 0

    def is_full(self):
        return self.top >= self.SIZE - 1

    def push(self, val):
        if self.is_full():
            print("Stack Overflow")
            return
        self.top += 1
        self.arr[self.top] = val

    def pop(self):
        if self.is_empty():
            print("Stack Underflow")
            return
        self.top -= 1

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return -1
        return self.arr[self.top]

    def display(self):
        if self.is_empty():
            print("Stack is empty")
            return
        for i in range(self.top, -1, -1):
            print(self.arr[i], end=" ")
        print()

s = Stack()
while True:
    val = int(input())
    if val == -1:
        break
    s.push(val)

s.display()
s.pop()
s.display()
print("Top element:", s.peek())