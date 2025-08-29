#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;

    Node(int val){
        data=val;
        addr=nullptr;
    }
};

class Linkedlist{
private:
    Node *head;
public:
    Linkedlist(){
        head = nullptr;
    }

    void insertAtEnd(int val){
        Node *newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
        }
        else{
            Node *temp = head;
            while (temp->addr != nullptr){
                temp = temp->addr;
            }
            temp->addr = newNode;
        }
    }


    void insertAtPosition(int val,int pos){
        Node *newNode = new Node(val);

        if(pos==1){
            newNode->addr = head;
            head=newNode;
            return;
        }
        Node *temp = head;
        int count = 1;

        while(temp!=nullptr && count < pos-1){
            temp=temp->addr;
            count++;
        }

        if(temp==nullptr){
            cout<<"Position out of bounds"<<endl;
            delete newNode;
            return;
        }
        newNode->addr = temp->addr;
        temp->addr=newNode;
        
    }
    void display(){
        if(head == nullptr){
            cout<<"LinkedList is Empty";
            return;
        }
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->addr;
        }
        cout<<endl;
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
            ll.insertAtEnd(val);
    }while(val!=-1);
    
    int val1,pos;
    cin>>val1>>pos;
    ll.insertAtPosition(val1,pos);
    ll.display();
    return 0;
}