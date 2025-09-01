#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *head= NULL;

void insertatend(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr =NULL;

    if(head==NULL)
        head=newNode;
    else{
        struct Node *temp = head;
        while (temp->addr!=NULL){
            temp=temp->addr;
        }
        temp->addr=newNode;
    }
}

void deleteFromEnd(){
    if(head==NULL){
        printf("Linkedlist is Empty Can't delete");
        return;
    }

    if (head->addr == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;    
    while(temp->addr->addr!=NULL)
    {
        temp=temp->addr;
    }
    free(temp->addr);
    temp->addr = NULL;
}

void display(){
    if(head==NULL){
        printf("List is Empty");
    }
    struct Node *temp = head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->addr;
    }
    printf("\n");
}

int main(){
    int val;

    do{
        scanf("%d",&val);
        if(val!=-1)
            insertatend(val);
    }while(val!=-1);
    deleteFromEnd();
    display();
    return 0;
}