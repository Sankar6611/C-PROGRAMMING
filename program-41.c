#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert_end(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x; n->next = NULL;
    if (!head) { head = n; return; }
    Node* p = head; while (p->next) p = p->next;
    p->next = n;
}

void delete_value(int x) {
    if (!head) { printf("List empty\n"); return; }
    if (head->data == x) { Node* t = head; head = head->next; free(t); printf("%d deleted\n", x); return; }
    Node* p = head;
    while (p->next && p->next->data != x) p = p->next;
    if (!p->next) { printf("%d not found\n", x); return; }
    Node* t = p->next; p->next = t->next; free(t);
    printf("%d deleted\n", x);
}

void display() {
    printf("List: ");
    for (Node* p = head; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    insert_end(10); insert_end(20); insert_end(30);
    display();
    delete_value(20); display();
    delete_value(50);
    return 0;
}
