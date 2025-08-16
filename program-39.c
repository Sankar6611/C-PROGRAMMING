#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed\n"); return; }
    n->data = x;
    n->next = top;
    top = n;
    printf("%d pushed\n", x);
}

void pop() {
    if (!top) { printf("Stack Underflow\n"); return; }
    Node* t = top;
    printf("%d popped\n", t->data);
    top = top->next;
    free(t);
}

void display() {
    if (!top) { printf("Stack is empty\n"); return; }
    printf("Stack (top->bottom): ");
    for (Node* p = top; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    push(10); push(20); push(30);
    display();
    pop(); display();
    return 0;
}
