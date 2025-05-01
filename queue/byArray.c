#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

typedef struct queue {
    int front;
    int rear;
    int queue[SIZE];
}queue;

void init(queue *q) {
    q->front = -1;
    q->rear = -1;
}
bool isEmpty(queue *q) {
    return q->front == -1 || q->front > q->rear;
}

bool isFull(queue *q) {
    return q->rear == SIZE - 1;
}
void enqueue(queue *q, int val) {
    if(isFull(q)) {
        printf("Queue is full");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->queue[++(q->rear)] = val;
}
int dequeue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty");
        return -1;
    }   
    return q->queue[(q->front)++];;
}
void display(queue *q) {
    for(int i=q->front; i <= q->rear; i++) {
        printf(" %d ", q->queue[i]);
    }
    printf("\n");
}


// Main function
int main() {
    queue *q;
    init(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);  // Output: 10 20 30

    printf("Dequeued: %d\n", dequeue(q));  // Output: 10
    display(q);                            // Output: 20 30

    return 0;
}
