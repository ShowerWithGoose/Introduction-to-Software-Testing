#include <stdio.h>
#include <stdlib.h>
void addTree(struct node **, int);
struct node *createTree(int);
void searchLeave(struct node *, int);

struct node {
    int data;
    struct node *Lchild;
    struct node *Rchild;
};

int main() {
    int n;
    struct node *head = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int data;
        scanf("%d", &data);
        addTree(&head, data);
    }
    searchLeave(head, 1);
    return 0;
}

void addTree(struct node **head, int data) {
    struct node *newNode = createTree(data);
    if (*head == NULL) {
        *head = newNode;



    } else {
        struct node *temp = *head;
        while (1) {
            if (data < temp->data) {
                if (temp->Lchild != NULL) {
                    temp = temp->Lchild;
                } else {
                    temp->Lchild = newNode;
                    break;
                }
            }
            if (data >= temp->data) { // @@ Logical error: should be 'else if' or 'else'. Without it, if the first condition is true and traversal continues, the second condition is evaluated against the updated 'temp' in the same loop iteration, causing incorrect traversal or insertion.
                if (temp->Rchild != NULL) {
                    temp = temp->Rchild;
                } else {
                    temp->Rchild = newNode;
                    break;
                }
            }
        }
    }
    return;
}

struct node *createTree(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
    return newNode;
}

void searchLeave(struct node *temp, int height) { // @@ Missing NULL check: if 'temp' is NULL (e.g., when n=0), accessing temp->Lchild will cause a segmentation fault.
    if (temp->Lchild == NULL && temp->Rchild == NULL) {
        printf("%d %d\n", temp->data, height);

    }

    if (temp->Lchild != NULL) {
        searchLeave(temp->Lchild, height + 1);

    }

    if (temp->Rchild != NULL) {
        searchLeave(temp->Rchild, height + 1);
    }

    return;
}