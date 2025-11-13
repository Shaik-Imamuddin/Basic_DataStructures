#include<iostream>
using namespace std;

#define SIZE 100

class Stack{
private:
    int arr[SIZE];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return top < 0;
    }

    bool isFull(){
        return top >= SIZE - 1;
    }

    void push(int val){
        if (isFull()){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    void pop(){
        if (isEmpty()){
            cout<<"Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek(){
        if (isEmpty()) {
            cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display(){
        if (isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        for (int i=top; i>=0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int val;

    while(true){
        cin >> val;
        if(val == -1)
            break;
        s.push(val);
    }
    s.display();
    s.pop();
    s.display();

    cout << "Top element: " << s.peek() << endl;
    return 0;
}