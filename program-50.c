#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

int hash(int key){ return key % TABLE_SIZE; }

void insert(int key){
    int idx = hash(key);
    Node* n=(Node*)malloc(sizeof(Node));
    n->key=key; n->next=table[idx];
    table[idx]=n;
    printf("%d inserted at index %d\n", key, idx);
}

Node* search(int key){
    int idx=hash(key);
    Node* p=table[idx];
    while(p){ if(p->key==key) return p; p=p->next; }
    return NULL;
}

void delete_key(int key){
    int idx=hash(key);
    Node *p=table[idx], *prev=NULL;
    while(p && p->key!=key){ prev=p; p=p->next; }
    if(!p){ printf("%d not found\n", key); return; }
    if(prev) prev->next=p->next; else table[idx]=p->next;
    free(p);
    printf("%d deleted from index %d\n", key, idx);
}

void display(){
    for(int i=0;i<TABLE_SIZE;i++){
        printf("[%d]: ", i);
        Node* p=table[i];
        while(p){ printf("%d -> ", p->key); p=p->next; }
        printf("NULL\n");
    }
}

int main(){
    // init table
    for(int i=0;i<TABLE_SIZE;i++) table[i]=NULL;

    insert(10); insert(20); insert(15); insert(7); insert(14);
    display();

    printf("Search 15: %s\n", search(15)?"Found":"Not Found");
    delete_key(20);
    delete_key(99);
    display();
    return 0;
}
