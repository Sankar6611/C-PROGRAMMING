#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* head = NULL;

void insert_end(int x) {
    DNode* n = (DNode*)malloc(sizeof(DNode));
    n->data = x; n->next = NULL; n->prev = NULL;
    if (!head) { head = n; return; }
    DNode* p = head; while (p->next) p = p->next;
    p->next = n; n->prev = p;
}

void delete_value(int x) {
    if (!head) { printf("List empty\n"); return; }
    DNode* p = head;
    while (p && p->data != x) p = p->next;
    if (!p) { printf("%d not found\n", x); return; }
    if (p->prev) p->prev->next = p->next; else head = p->next;
    if (p->next) p->next->prev = p->prev;
    free(p); printf("%d deleted\n", x);
}

void display_forward() {
    printf("Forward: ");
    DNode* p = head; while (p) { printf("%d ", p->data); if (!p->next) break; p = p->next; }
    printf("\n");
}

void display_backward() {
    if (!head) { printf("Backward: \n"); return; }
    DNode* p = head; while (p->next) p = p->next;
    printf("Backward: ");
    while (p) { printf("%d ", p->data); p = p->prev; }
    printf("\n");
}

int main() {
    insert_end(1); insert_end(2); insert_end(3);
    display_forward(); display_backward();
    delete_value(2);
    display_forward(); display_backward();
    return 0;
}
