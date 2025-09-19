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

void deleteFromPosition(int pos){
    if(head==NULL){
        printf("Linked list is Empty");
        return;
    }

    if(pos<0){
        printf("Invalid Position");
        return;
    }

    struct Node* temp = head;

    if(pos == 1){
        head = temp->addr;
        printf("%d is Deleted\n",temp->data);
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for(int i=1;temp!=NULL && i<pos;i++){
        prev = temp;
        temp = temp->addr;
    }

    if(temp == NULL){
        printf("Position Out of range\n");
    }

    prev->addr = temp->addr;
    printf("%d is Deleted\n",temp->data);
    free(temp);
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
    int val,pos;

    do{
        scanf("%d",&val);
        if(val!=-1)
            insertatend(val);
    }while(val!=-1);

    scanf("%d",&pos);
    deleteFromPosition(pos);
    display();
    return 0;
}