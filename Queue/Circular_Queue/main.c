#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val){
    struct Node *newNode  = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;

    if(front==NULL){
        front=rear=newNode;
        newNode->addr=front;
    }
    else{
        rear->addr = newNode;
        rear = newNode;
        rear->addr = front;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Queue underflow");
        return;
    }

    if(front==rear){
        printf("%d",front->data);
        free(front);
        front=rear=NULL;
    }

    else{
        struct Node *temp=front;
        printf("%d\n",temp->data);
        front = front->addr;
        rear->addr = front;
        free(temp);
    }
}

void peek(){
    if(front==NULL){
        printf("Queue is Empty");
        return;
    }
    printf("Front Element: %d\n",front->data);
}

void display(){
    if(front==NULL){
        printf("Queue is Empty");
        return;
    }

    struct Node *temp = front;
    do{
        printf("%d ",temp->data);
        temp = temp->addr;
    }while(temp!=front);
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