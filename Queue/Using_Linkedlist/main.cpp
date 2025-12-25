#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;
    Node(int val){
        data=val;
        addr=NULL;
    }
};

Node *front=NULL;
Node *rear=NULL;

void enqueue(int val){
    Node *newNode = new Node(val);
    if(rear==NULL){
        front=rear=newNode;
    } else {
        rear->addr=newNode;
        rear=newNode;
    }
}

void dequeue(){
    if(front==NULL){
        cout<<"Queue Underflow!\n";
        return;
    }
    Node *temp=front;
    cout<<front->data<<"\n";
    front=front->addr;
    if(front==NULL) rear=NULL;
    delete temp;
}

void peek(){
    if(front==NULL){
        cout<<"Queue is empty!\n";
        return;
    }
    cout<<"Front element: "<<front->data<<"\n";
}

void display(){
    if(front==NULL){
        cout<<"Queue is empty!\n";
        return;
    }
    Node *temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->addr;
    }
    cout<<"\n";
}

int main(){
    int val;
    do{
        cin>>val;
        if(val!=-1)
            enqueue(val);
    }while(val!=-1);

    display();
    dequeue();
    peek();
    display();

    return 0;
}