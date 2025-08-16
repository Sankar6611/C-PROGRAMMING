#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed\n"); return; }
    n->data = x; n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
    printf("%d enqueued\n", x);
}

void dequeue() {
    if (!front) { printf("Queue Underflow\n"); return; }
    Node* t = front;
    printf("%d dequeued\n", t->data);
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void display() {
    if (!front) { printf("Queue is empty\n"); return; }
    printf("Queue (front->rear): ");
    for (Node* p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    enqueue(5); enqueue(15); enqueue(25);
    display();
    dequeue(); display();
    return 0;
}
