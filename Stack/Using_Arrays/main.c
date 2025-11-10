#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct{
    int arr[SIZE];
    int top;
}Stack;

void push(Stack *s, int value) {
    if (s->top >= SIZE - 1) {
        printf("Stack Overflow !.%d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

void pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow!\n");
        return;
    }
    s->top--;
}

int peek(Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

void display(Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    s.top = -1;   
    int val;

    while (true) {
        scanf("%d", &val);
        if (val == -1)
            break;
        push(&s, val);
    }

    display(&s);
    pop(&s);
    display(&s);

    printf("Top element: %d\n", peek(&s));
    return 0;
}