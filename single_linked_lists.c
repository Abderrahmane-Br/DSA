#include "stdlib.h"
#include "stdio.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* creatNode(int val);
void append(Node* head, int val);
void preppend(Node* head, int val);
Node* removeFirst(Node* head);
Node* removeLast(Node* head);
void printList(Node* head);


int main() {
    Node* head = creatNode(5);

    append(head, 6);
    preppend(head, 3);
    printList(head);
}

Node* creatNode(int val) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;
    return new;
}

void preppend(Node *head, int val){
    Node *new = creatNode(val);
    new->next = head;
    head = new;
    free(new);
}

void append(Node* head, int val) {
    Node *new = creatNode(val);

    if (head->next == NULL) {
        head->next = new;
        return;
    }

    Node *curr = (Node*) malloc(sizeof(Node));
    curr = head;

    while(curr->next != NULL)
        curr = curr->next;

    curr->next = new;
    free(curr);
    free(new);
};

void printList(Node *head) {
    Node *curr = (Node*) malloc(sizeof(Node));
    curr = head;
    if(head != NULL) {
        printf("not null\n");
        while(curr != NULL) {
            printf("%d->", curr->data);
            curr = curr->next;
        }  
    }
}