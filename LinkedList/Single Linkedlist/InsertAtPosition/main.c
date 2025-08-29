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

void insertAtPosition(int val,int pos){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr = NULL;
    
    if (pos==1){
        newNode->addr = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp!=NULL && count<pos-1){
        temp = temp->addr;
        count++;
    }

    if(temp==NULL){
        printf("Position out of bounds..\n");
        free(newNode);
        return;
    }
    
    newNode->addr = temp->addr;
    temp->addr = newNode;   
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

    int val1,pos;
    scanf("%d%d",&val1,&pos);
    insertAtPosition(val1,pos);
    display();
    return 0;
}