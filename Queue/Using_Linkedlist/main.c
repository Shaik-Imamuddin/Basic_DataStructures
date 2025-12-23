#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr = NULL;

    if(rear==NULL){ 
        front = rear = newNode;
    } 
    else{
        rear->addr = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = front;
    printf("%d\n", temp->data);
    front = front->addr;
    if(front==NULL) rear=NULL;
    free(temp);
}

void peek(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->addr;
    }
    printf("\n");
}

int main(){
    int val;
    do{
        scanf("%d",&val);
        if(val!=-1)
            enqueue(val);
    }while(val!=-1);

    display();
    dequeue();
    peek();
    display();

    return 0;
}