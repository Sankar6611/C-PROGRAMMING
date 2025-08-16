#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int k){
    Node* n=(Node*)malloc(sizeof(Node));
    n->key=k; n->left=n->right=NULL; return n;
}

Node* insert(Node* root, int k){
    if(!root) return newNode(k);
    if(k < root->key) root->left = insert(root->left, k);
    else if(k > root->key) root->right = insert(root->right, k);
    return root;
}

Node* search(Node* root, int k){
    if(!root || root->key==k) return root;
    return (k < root->key) ? search(root->left,k) : search(root->right,k);
}

Node* minNode(Node* root){ while(root->left) root=root->left; return root; }

Node* delete(Node* root, int k){
    if(!root) return NULL;
    if(k < root->key) root->left = delete(root->left, k);
    else if(k > root->key) root->right = delete(root->right, k);
    else {
        if(!root->left){ Node* r=root->right; free(root); return r; }
        else if(!root->right){ Node* l=root->left; free(root); return l; }
        Node* s=minNode(root->right);
        root->key=s->key;
        root->right=delete(root->right, s->key);
    }
    return root;
}

void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->key); inorder(r->right); }

int main(){
    Node* root=NULL;
    int keys[]={50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root=insert(root, keys[i]);

    printf("Inorder: "); inorder(root); printf("\n");

    int x=40;
    printf("Search %d: %s\n", x, search(root,x)?"Found":"Not Found");

    root=delete(root, 50);
    printf("After deleting 50, Inorder: "); inorder(root); printf("\n");
    return 0;
}
