#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        prev=nullptr;
        next=nullptr;
    }
};

class DoublyLinkedList{
private:
    Node* head;

public:
    DoublyLinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while (temp->next!=nullptr){ 
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    }

    void deleteFromEnd(){
        if (head==nullptr){
            cout << "List is Empty, can't delete\n";
            return;
        }

        if (head->next==nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp=head;
        while (temp->next!=nullptr) {
            temp = temp->next;
        }

        temp->prev->next=nullptr;
        delete temp;
    }

    void displayForward() {
        if (head==nullptr) {
            cout<<"List is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp!=nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void displayBackward(){
        if (head == nullptr){
            cout<<"List is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next!=nullptr){ 
            temp = temp->next;
        }
        while (temp!=nullptr){
            cout<<temp->data << " ";
            temp = temp->prev;
        }
        cout<<"\n";
    }

    ~DoublyLinkedList(){
        Node* temp;
        while (head!=nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int val;
    do {
        cin >> val;
        if (val!=-1)
            dll.insertAtEnd(val);
    } while (val!=-1);

    dll.deleteFromEnd();
    dll.displayForward();
    dll.displayBackward();
    return 0;
}
