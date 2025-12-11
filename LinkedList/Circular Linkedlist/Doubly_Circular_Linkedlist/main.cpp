#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);

        if (head == nullptr){
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } 
        else{
            Node* temp = head->prev; 

            newNode->next = head;
            newNode->prev = temp;

            temp->next = newNode;
            head->prev = newNode;
        }
    }

    void displayForward(){
        if (head==nullptr){
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;

        while (temp->next!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<"\n";
    }

    void displayBackward(){
        if(head==nullptr){
            cout<<"List is Empty\n";
            return;
        }

        Node* temp=head->prev; 

        while(temp!=head){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }

        cout<<head->data<<"\n";
    }

    ~LinkedList(){
        if(head==nullptr)
            return;

        Node* temp=head->next;

        while(temp!=head){
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        delete head;
    }
};

int main(){
    LinkedList cdll;
    int val;

    do{
        cin>>val;
        if (val!=-1)
            cdll.insertAtEnd(val);
    } while(val!=-1);

    cdll.displayForward();
    cdll.displayBackward();

    return 0;
}