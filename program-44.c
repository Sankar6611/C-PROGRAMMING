#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* n;
    struct QNode* next;
} QNode;

typedef struct {
    QNode *front, *rear;
} Queue;

void q_init(Queue* q){ q->front=q->rear=NULL; }
int q_empty(Queue* q){ return q->front==NULL; }
void q_push(Queue* q, Node* n){
    QNode* x=(QNode*)malloc(sizeof(QNode));
    x->n=n; x->next=NULL;
    if(!q->rear) q->front=q->rear=x;
    else { q->rear->next=x; q->rear=x; }
}
Node* q_pop(Queue* q){
    if(q_empty(q)) return NULL;
    QNode* t=q->front; Node* n=t->n;
    q->front=t->next; if(!q->front) q->rear=NULL; free(t); return n;
}

Node* newNode(int x){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=x; n->left=n->right=NULL; return n;
}

void preorder(Node* r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }
void levelorder(Node* r){
    if(!r) return;
    Queue q; q_init(&q); q_push(&q, r);
    while(!q_empty(&q)){
        Node* cur=q_pop(&q);
        printf("%d ", cur->data);
        if(cur->left) q_push(&q, cur->left);
        if(cur->right) q_push(&q, cur->right);
    }
}

int main(){
    // Build a sample tree:
    //       1
    //     /   \
    //    2     3
    //   / \   /
    //  4  5  6
    Node* root=newNode(1);
    root->left=newNode(2); root->right=newNode(3);
    root->left->left=newNode(4); root->left->right=newNode(5);
    root->right->left=newNode(6);

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Level order: "); levelorder(root); printf("\n");
    return 0;
}
