#include<iostream>
using namespace std;

#define SIZE 100

class Queue{
private:
    int arr[SIZE];
    int front,rear;

public:
    Queue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return front==-1 || front>rear;
    }

    bool isFull(){
        return rear>=SIZE-1;
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        if(front==-1)
            front=0;
        arr[++rear]=val;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<arr[front++]<<"\n";
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Queue q;
    int val;

    while(true){
        cin>>val;
        if(val==-1)
            break;
        q.enqueue(val);
    }

    q.display();
    q.dequeue();
    cout<<"Front element: "<<q.peek()<<endl;
    q.display();

    return 0;
}