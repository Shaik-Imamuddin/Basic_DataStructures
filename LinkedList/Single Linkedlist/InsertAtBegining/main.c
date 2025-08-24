#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *head=NULL;

void insertatbeginning(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->addr==NULL;

    newNode->addr=head;
    head=newNode;
}

void display(){
    struct Node *temp = head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->addr;
    }
}

int main(){
    int val;
    do{
        scanf("%d",&val);
        if(val!=-1)
            insertatbeginning(val);
    }while(val!=-1);
    display();
    return 0;
}
