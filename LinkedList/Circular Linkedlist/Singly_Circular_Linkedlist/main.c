#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *head = NULL;

void insertatend(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr = NULL;

    if(head == NULL){
        head = newNode;
        newNode->addr = head;     
    }
    else{
        struct Node *temp = head;
        while(temp->addr != head){
            temp = temp->addr;
        }
        temp->addr = newNode;
        newNode->addr = head;     
    }
}

void display(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->addr;
    }while(temp != head);
    printf("\n");
}

int main(){
    int val;

    do{
        scanf("%d",&val);
        if(val != -1)
            insertatend(val);
    }while(val != -1);

    display();
    return 0;
}