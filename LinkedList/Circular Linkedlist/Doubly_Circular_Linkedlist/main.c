#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else{
        struct Node *temp = head->prev;  

        newNode->next = head;
        newNode->prev = temp;

        temp->next = newNode;
        head->prev = newNode;
    }
}

void displayForward(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);   
}

void displayBackward(){
    if (head == NULL){
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head->prev;  

    while (temp != head){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("%d\n", head->data);   
}

int main(){
    int val;

    do{
        scanf("%d", &val);
        if (val != -1)
            insertAtEnd(val);
    } while (val != -1);

    displayForward();
    displayBackward();
    return 0;
}