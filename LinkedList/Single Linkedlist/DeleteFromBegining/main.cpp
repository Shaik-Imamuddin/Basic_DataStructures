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

    void deleteFromEnd(){
        if(head == nullptr){
            cout<<"LinkedList is Empty Can't delete";
            return;
        }
        if(head->addr == nullptr){
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->addr->addr != nullptr){
            temp=temp->addr;
        }
        delete temp->addr;
        temp->addr = nullptr;
    }

    void deleteFromBegining(){
        if(head==nullptr){
            printf("Linkedlist is Empty.Can't delete");
            return;
        }
        Node *temp = head;
        head = head->addr;
        delete temp;
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
    ll.deleteFromBegining();
    ll.display();
    return 0;
}