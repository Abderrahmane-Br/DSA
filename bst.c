#include "stdlib.h"
#include "stdio.h"

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* creatNode(int val){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
};

void add(Node **root, int val) {
    Node *new = creatNode(val);
    if (*root == NULL){
        *root = new;
    }
    else {
        if ((*root)->data>val)
            add(&((*root)->left), val);
        else if((*root)->data<val)
            add(&((*root)->right), val);
    }
};

Node* add2(Node *root, int val) {
    if (root == NULL){
        root = creatNode(val);
    }
    else {
        if (root->data>val)
            root->left = add2(root->left, val);
        else if(root->data<val)
            root->right = add2(root->right, val);
    }
    return root;
};

//visualizing the tree
void visBST(Node* root, int indent){
    if(root != NULL){
        indent += 2;
        int i;
        // for (i=0; i<indent; i++)
        //     printf(" ");
        // printf("\n");
        visBST(root->right, indent);
        printf("\n");
        for (i=0; i<indent; i++)
            printf("   ");
        printf("%d", root->data);
        visBST(root->left, indent);
    }
}

void printBST(Node* root){
    if(root != NULL){
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }
}

Node* getRightMostNode(Node *root){
    //this function assumes root is not NULL
    if (root->right == NULL)
        return root;
    else
        return getRightMostNode(root->right);
}

Node* getPredecessor(Node *root) {
    if(root->left == NULL) 
        return root;
    else 
        return getRightMostNode(root->left);
}



Node* removeNode(Node* root, int target) {
    Node *curr = root;
    if(curr != NULL){
        if(curr->data == target) {
            if(curr->left != NULL && curr->right != NULL){
                int data = getPredecessor(curr)->data;
                removeNode(curr, data);
                curr->data = data;
            }
            else if(curr->left == NULL)
                curr = curr->right;
            else 
                curr = curr->left;
        }
        else if(curr->data>target)
            curr->left = removeNode(curr->left, target);
        else 
            curr->right = removeNode(curr->right, target);
    }

    return curr;

}

int main() {
    Node* root = creatNode(9);
    root = add2(root, 5);
    root = add2(root, 7);
    root = add2(root, 3);
    root = add2(root, 1);
    root = add2(root, 4);
    root = add2(root, 6);
    root = add2(root, 13);
    root = add2(root, 12);
    root = add2(root, 17);
    root = add2(root, 8);
    visBST(root, 1);
    printf("\n");
    // printBST(root);
    printf("%d", getPredecessor(root)->data);
    root = removeNode(root, 5);
    visBST(root, 1);
    root = removeNode(root, 13);
    visBST(root, 1);
    root = removeNode(root, 7);
    visBST(root, 1);
    return 0;
}