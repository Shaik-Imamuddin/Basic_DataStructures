#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top=-1;

void push(int val){
    if(top==SIZE-1){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top]=val;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d\n",stack[top--]);
}

void peek(){
    if(top==-1){
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n",stack[top]);
}

void display(){
    if(top==-1){
        printf("Stack is empty!\n");
        return;
    }
    for(int i=top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int val;
    do{
        scanf("%d",&val);
        if(val!=-1)
            push(val);
    }while(val!=-1);

    display();
    pop();
    peek();
    display();
    return 0;
}