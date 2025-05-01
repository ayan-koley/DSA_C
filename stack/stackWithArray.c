#include<stdio.h>
#include<stdbool.h>
#define SIZE 20

typedef struct stack {
    int top;
    int stack[SIZE];
    
}stack;
void init(stack *s) {
    s->top = -1;
}
bool isEmpty(stack *s) {
    return s->top == -1;
}
bool isFull(stack *s) {
    return s->top == SIZE - 1;
}
void push(stack *s, int data) {
    if(isFull(s)) {
        printf("Stack is full");
        return;
    }
    s->stack[++(s->top)] = data;
}
int pop(stack *s) {
    if(isEmpty(s)) {
        printf("Stack is already emptyout");
        return -1;
    }
    return s->stack[(s->top)--];
}
int peek(stack *s) {
    if(isEmpty(s)) {
        printf("Stack is already emptyout");
        return -1;
    }
    return s->stack[s->top];
}
void display(stack *s) {
    for(int i=0; i <= s->top; i++) {
        printf(" %d ", s->stack[i]);
    }
    printf("\n");
}
int main() {
    stack *s;
    init(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);   // Output: 30 20 10

    printf("Popped: %d\n", pop(s));  // Output: 30
    display(s);                      // Output: 20 10

    printf("Top: %d\n", peek(s));    // Output: 20

    return 0;
}