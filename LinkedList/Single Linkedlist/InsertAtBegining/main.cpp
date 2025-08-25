#include<iostream>
using namespace std;

//Node Creation
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

    //insert data at beginning
    void insertAtBegining(int val){
        Node *newNode = new Node(val);
        newNode->addr = head;
        head=newNode;
    }

    //display the data 
    void display(){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->addr;
        }
    }

    //de-allocating the memory
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

    //Enter values to insert
    //-1 to stop
    do{
        cin>>val;
        if(val!=-1){
            ll.insertAtBegining(val);
        }
    }while(val!=-1);

    ll.display();
    return 0;
}