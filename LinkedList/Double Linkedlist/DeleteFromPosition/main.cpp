#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { // Traverse to last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteFromPosition(int pos) {
        if (head == nullptr) {
            cout << "Linkedlist is Empty";
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "Linkedlist is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayBackward() {
        if (head == nullptr) {
            cout << "Linkedlist is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) { 
            temp = temp->next;
        }
        while (temp != nullptr) { 
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int val,pos;
    do{
        cin >> val;
        if(val!=-1)
            dll.insertAtEnd(val);
    }while(val!=-1);

    cin>>pos;
    dll.deleteFromPosition(pos);
    dll.displayForward();
    dll.displayBackward();
    return 0;
}