#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int i;
    struct node *next;
};
int main() {
    int n,i,j,k;
    struct node *p=NULL,*q=NULL,*top,*head;
    head=(struct node*)malloc(sizeof(struct node));
    top=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->i=0;
    head->data=0;
    p=q=head;
    while(scanf("%d",&n)!=EOF) {
        if(n==1) {
            scanf("%d",&i);
            if(p->i==100) { // @@ [Error: The stack capacity check uses p->i, but p->i tracks the index of the last node, not the stack size. The maximum capacity is 100, so the condition should check if the stack size (p->i) is >= 100, but the initial head->i is 0, so after pushing 100 elements, p->i would be 100, making this condition correct. However, the problem requires outputting "error " (with a space) for full stack push, but this code outputs "error\n" (with newline).]
                printf("error\n"); // @@ [Error: Should output "error " (with a space) instead of "error\n" (with newline) to match the expected output format.]
            } else {
                struct node *new1 = (struct node*)malloc(sizeof(struct node));
                new1->data=i;
                new1->next=NULL;
                new1->i=p->i+1;
                p->next=new1;
                p=new1;
            }
        } else if(n==0){
            if(p->i==0) { // @@ [Error: The condition checks if p->i is 0, but p points to the top node. When the stack is empty, p should point to head (which has i=0), so this correctly detects empty stack. However, the problem requires outputting "error " (with a space) for empty pop, but this code outputs "error\n" (with newline).]
                printf("error\n"); // @@ [Error: Should output "error " (with a space) instead of "error\n" (with newline) to match the expected output format.]
            } else {
                printf("%d\n",p->data); // @@ [Error: Should output the popped element followed by a space, not a newline. The expected output format requires spaces between elements and a space after the last element.]
                struct node *temp = head;
                while (temp->next!=p) {
                    temp = temp->next;
                }
                temp->next=NULL;
                p = temp;
                p->next = NULL;
            }
        }
    }
    while (head->next != NULL) {
        p = head->next;
        head->next = p->next;
        free(p);
    }
    free(head);
    return 0;
}