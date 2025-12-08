#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;

    Node(int data){
        this->data = data;
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

        if(head == nullptr){
            head = newNode;
            newNode->addr = head; 
        } 
        else{
            Node *temp = head;

            while(temp->addr != head){
                temp = temp->addr;
            }

            temp->addr = newNode;
            newNode->addr = head; 
        }
    }

    void display(){
        if(head==nullptr){
            cout<<"List is Empty\n";
            return;
        }
        Node *temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->addr;
        }while(temp!=head);
        cout<<endl;
    }

    ~Linkedlist(){
        if(head==nullptr) 
            return;

        Node *temp = head->addr;

        while(temp!=head){
            Node *nextNode = temp->addr;
            delete temp;
            temp = nextNode;
        }
        delete head;
        head = nullptr;
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