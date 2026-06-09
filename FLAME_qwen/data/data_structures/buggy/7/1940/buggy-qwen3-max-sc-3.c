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
            if (data >= temp->data) { // @@ [This condition is not in an else block, so both if blocks may execute for the same node when data >= temp->data, leading to incorrect insertion logic. After inserting into left child, it may also try to insert into right child in same loop iteration.]
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
    if (temp == NULL) return; // @@ [Missing null check before accessing temp->Lchild and temp->Rchild. If head is NULL (n=0), this function will dereference a null pointer, causing runtime error. However, since the error type reported is "Compilation Error", this is likely not the primary issue. But note: the actual compilation error is due to missing #include <stdlib.h> being present but possibly insufficient in some environments? Actually, the real issue is that the code compiles fine in most C compilers. Given the test output "/bin/sh: 1: gcc: not found", this indicates the environment lacks a compiler, not a code error. But per instructions, we must find logical/semantic errors matching failed test cases. Re-examining: the problem says "Compilation Error", yet the provided code includes stdlib.h and uses malloc correctly. However, the true logical flaw is in addTree's double-if causing potential double insertion attempt. Also, the traversal order in searchLeave is correct (in-order would be left-root-right, but here it's pre-order with leaf check first). But the main bug is the non-exclusive conditions in addTree.]
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