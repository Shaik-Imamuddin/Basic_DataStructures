#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;

void insertAtEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;

    if (head==NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFromEnd() {
    if (head==NULL) {
        printf("List is Empty, can't delete\n");
        return;
    }

    if (head->next==NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next!=NULL) { 
        temp = temp->next;
    }

    temp->prev->next = NULL; 
    free(temp);
}

void displayForward() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
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
            insertAtEnd(val);
    }while(val != -1);

    deleteFromEnd();

    displayForward();
    displayBackward();
    return 0;
}
