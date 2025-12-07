#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* addr;
};

Node* head = NULL;

void insertAtEnd(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->addr = NULL;

    if (head == NULL){
        head = newNode;
        newNode->addr = head;
    } else{
        Node* temp = head;
        while (temp->addr != head){
            temp = temp->addr;
        }
        temp->addr = newNode;
        newNode->addr = head;
    }
}

void display(){
    if (head == NULL){
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->addr;
    }while(temp!=head);
    cout<<endl;
}

int main(){
    int val;

    do{
        cin>>val;
        if (val != -1)
            insertAtEnd(val);
    }while(val != -1);
    display();
    return 0;
}