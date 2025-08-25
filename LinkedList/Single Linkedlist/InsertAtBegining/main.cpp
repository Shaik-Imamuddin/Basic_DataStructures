#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addr;
    Node(int val){
        data = val;
        addr = nullptr;
    }
};

class Linkeslist{
private:
    Node *head;
public:
    Linkeslist(){
        head = nullptr;
    }

    void insertAtBegining(int val){
        Node *newNode = new Node(val);
        newNode->addr = head;
        head=newNode;
    }

    void display(){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->addr;
        }
    }

    ~Linkeslist(){
        Node *temp;
        while (head!=nullptr){
            temp=head;
            head=head->addr;
            delete temp;
        } 
    }
};

int main(){
    Linkeslist ll;
    int val;

    do{
        cin>>val;
        if(val!=-1){
            ll.insertAtBegining(val);
        }
    }while(val!=-1);

    ll.display();
    return 0;
}