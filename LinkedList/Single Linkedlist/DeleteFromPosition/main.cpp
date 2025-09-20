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

    void deleteFromPosition(int pos){
        if(head == nullptr){
            cout<<"Linked list is Empty";
            return;
        }

        if(pos<0){
            cout<<"Invalid Position";
            return;
        }

        Node *temp = head;

        if(pos == 1){
            head = temp->addr;
            cout<<temp->data<<" is Deleted\n";
            delete temp;
            return;
        }

        Node *prev = nullptr;
        for (int i=1;temp!=nullptr && i<pos;i++){
            prev=temp;
            temp=temp->addr;
        }

        if(temp==nullptr){
            cout<<"Position out of range\n";
            return;
        }

        prev->addr = temp->addr;
        cout<<temp->data<<" is Deleted\n";
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
    int val,pos;

    do{
        cin>>val;
        if(val!=-1)
            ll.insertatend(val);
    }while(val!=-1);
    cin>>pos;
    ll.deleteFromPosition(pos);
    ll.display();
    return 0;
}