#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *addr;
};

Node *top=NULL;

void push(int val){
    Node *newNode=new Node();
    newNode->data=val;
    newNode->addr=top;
    top=newNode;
}

void pop(){
    if(top==NULL){
        cout<<"Stack Underflow!\n";
        return;
    }
    cout<<top->data<<"\n";
    Node *temp=top;
    top=top->addr;
    delete temp;
}

void peek(){
    if(top==NULL){
        cout<<"Stack is empty!\n";
        return;
    }
    cout<<"Top element: "<<top->data<<"\n";
}

void display(){
    if(top==NULL){
        cout<<"Stack is empty!\n";
        return;
    }
    Node *temp=top;
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
            push(val);
    }while(val!=-1);

    display();
    pop();
    peek();
    display();
    return 0;
}