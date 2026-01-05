#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = front;

    if(front==NULL)
        rear=newNode;
    else
        front->prev = newNode;
    
    front = newNode;
}

void insertRear(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = val;
    newNode->prev = rear;
    newNode->next = NULL;

    if(rear==NULL)
        front=newNode;
    else
        rear->next=newNode;
    
    rear=newNode;
}


void deleteFront(){
    if(front==NULL){
        printf("Dequeue Underflow");
        return;
    }

    struct Node *temp = front;
    front = front->next;

    if(front==NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear(){
    if(rear==NULL){
        printf("Dequeue Underflow");
        return;
    }

    struct Node *temp = rear;
    rear = rear->prev;

    if(rear==NULL)
        front=NULL;
    else
        rear->next = NULL;
    
    free(temp);
}

void display(){
    struct Node *temp = front;

    if(temp==NULL){
        printf("Dequeue is Empty");
        return;
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int val;

    do{
        scanf("%d",&val);
        if(val!=-1){
            if(val%2==0)
                insertRear(val);
            else
                insertFront(val);
        }
    }while(val!=-1);

    display();
    deleteFront();
    deleteRear();
    display();

    return 0;
}