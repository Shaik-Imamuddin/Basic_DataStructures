#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int val){
    if(rear==SIZE-1){
        printf("Queue Overflow!\n");
        return;
    }
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=val;
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d\n",queue[front]);
    front++;
}

void peek(){
    if(front==-1 || front>rear){
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n",queue[front]);
}

void display(){
    if(front==-1 || front>rear){
        printf("Queue is empty!\n");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
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