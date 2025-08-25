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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
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
        while (temp->next != nullptr)
            temp = temp->next;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int val;
    do {
        cin >> val;
        if (val != -1)
            dll.insertAtBeginning(val);
    } while (val != -1);

    dll.displayForward();
    dll.displayBackward();
    return 0;
}