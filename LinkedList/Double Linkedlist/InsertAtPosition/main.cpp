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

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 1) { 
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) { 
            cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is Empty\n";
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
            cout << "List is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) { // Move to last node
            temp = temp->next;
        }
        while (temp != nullptr) { // Traverse backward
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
    int val;
    do {
        cin >> val;
        if (val != -1)
            dll.insertAtEnd(val);
    } while (val != -1);

    dll.displayForward();
    dll.displayBackward();
    return 0;
}