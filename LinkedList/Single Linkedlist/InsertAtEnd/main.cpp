#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;

    Node(int data){
        this->data=data;
        addr = nullptr;
    }
};

class Linkedlist{
private:
    Node *head;
public:
    Linkedlist(){
        head = nullptr;
    }

    void insertatend(int val){
        Node *newNode = new Node(val);
        if(head==nullptr){
            head=newNode;
        } 
        else{
            Node *temp = head;
            while(temp->addr!=nullptr){
                temp=temp->addr;
            }
            temp->addr = newNode;
        }
    }

    void display(){
        Node *temp = head;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->addr;
        }        
    }

    ~Linkedlist(){
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->addr;
            delete temp;
        }
    }
};


int main(){
    Linkedlist ll;
    int val;

    do{
        cin>>val;
        if(val!=-1)
            ll.insertatend(val);
    }while(val!=-1);
    ll.display();
    return 0;
}