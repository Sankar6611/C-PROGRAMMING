#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* tail = NULL; // tail->next points to head

void insert_end(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    if (!tail) { tail = n; n->next = n; }
    else { n->next = tail->next; tail->next = n; tail = n; }
}

void delete_value(int x) {
    if (!tail) { printf("List empty\n"); return; }
    Node *curr = tail->next, *prev = tail;
    do {
        if (curr->data == x) {
            if (curr == prev) { // single node
                tail = NULL;
            } else {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
            }
            free(curr);
            printf("%d deleted\n", x);
            return;
        }
        prev = curr; curr = curr->next;
    } while (curr != tail->next);
    printf("%d not found\n", x);
}

void display() {
    if (!tail) { printf("List: \n"); return; }
    printf("List: ");
    Node* p = tail->next;
    do { printf("%d ", p->data); p = p->next; } while (p != tail->next);
    printf("\n");
}

int main() {
    insert_end(10); insert_end(20); insert_end(30);
    display();
    delete_value(20); display();
    delete_value(50);
    return 0;
}
