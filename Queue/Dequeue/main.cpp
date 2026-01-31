#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

Node* front=NULL;
Node* rear=NULL;

void insertFront(int val){
    Node* newNode=new Node(val);
    newNode->next=front;

    if(front==NULL)
        rear=newNode;
    else
        front->prev=newNode;

    front=newNode;
}

void insertRear(int val){
    Node* newNode=new Node(val);
    newNode->prev=rear;

    if(rear==NULL)
        front=newNode;
    else
        rear->next=newNode;

    rear=newNode;
}

void deleteFront(){
    if(front==NULL){
        cout<<"Dequeue Underflow\n";
        return;
    }

    Node* temp=front;
    front=front->next;

    if(front==NULL)
        rear=NULL;
    else
        front->prev=NULL;

    delete temp;
}

void deleteRear(){
    if(rear==NULL){
        cout<<"Dequeue Underflow\n";
        return;
    }

    Node* temp=rear;
    rear=rear->prev;

    if(rear==NULL)
        front=NULL;
    else
        rear->next=NULL;

    delete temp;
}

void display(){
    if(front==NULL){
        cout<<"Dequeue is Empty\n";
        return;
    }

    Node* temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int val;

    do{
        cin>>val;
        if(val!=-1){
            if(val%2==0)
                insertRear(val);
            else
                insertFront(val);
        }
    }while(val!=-1);

    display();
    deleteFront();
    deleteRear();
    display();

    return 0;
}