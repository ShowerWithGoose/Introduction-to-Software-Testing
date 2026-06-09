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
            if (data >= temp->data) { // @@ [This condition overlaps with the previous 'if' when data < temp->data is false. It should be 'else if' to avoid re-checking and potential double insertion logic path. However, this is a logical error, not a compilation error. The actual compilation error is missing inclusion of necessary headers or incorrect function declarations, but in this case, the real issue is that the code compiles fine. Given the reported error "/bin/sh: 1: gcc: not found", it's an environment issue, not a code error. But since the problem states there's a compilation error in the code, and the only plausible cause is undeclared functions used before definition without proper ordering or headers — however all functions are declared. Thus, the true compilation error may stem from using 'for (int i=...)' in C89 mode. If the compiler defaults to C89, declaring 'int i' inside for-loop causes compilation error.]
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

void searchLeave(struct node *temp, int height) {
    if (temp == NULL) return; // @@ [Missing null check before accessing temp->Lchild and temp->Rchild. When called with head=NULL (n=0), this leads to segmentation fault, but not compilation error. However, the original error is "gcc: not found", which is environmental. But per instructions, we must find a code-based compilation error. The only possible compilation error in strict C89 is the declaration of 'int i' inside the for loop in main().]
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