#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;

void insertAtEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
    } else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("Linkedlist is Empty\n");
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}


void displayForward(){
    if (head == NULL){
        printf("Linkedlist is Empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(){
    if (head == NULL){
        printf("Linkedlist is Empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL){ 
        temp = temp->next;
    }
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    int val,pos;
    do{
        scanf("%d", &val);
        if (val != -1)
            insertAtEnd(val);
    } while (val != -1);
    scanf("%d",&pos);
    deleteFromPosition(pos);
    displayForward();
    displayBackward();
    return 0;
}