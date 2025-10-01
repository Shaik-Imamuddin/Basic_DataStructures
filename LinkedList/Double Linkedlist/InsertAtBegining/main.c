#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void displayForward() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is Empty\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next; 
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int val;
    do {
        scanf("%d", &val);
        if (val != -1)
            insertAtBeginning(val);
    } while (val != -1);

    displayForward();
    displayBackward();
    return 0;
}