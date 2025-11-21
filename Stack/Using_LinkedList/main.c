#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *addr;
};

struct Node *top = NULL; 

void push(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->addr = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = top;
    printf("%d\n", temp->data);
    top = top->addr;
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}

int main(){
    int val;

    do{
        scanf("%d", &val);
        if (val != -1)
            push(val);
    }while(val != -1);

    display();
    pop();
    peek();
    display();
    return 0;
}