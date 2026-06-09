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
            if(p->i==100) { // @@ [Error: The stack capacity check uses p->i, but p points to the top node, not the head. The maximum capacity is 100, but the head node counts as one element, so the stack can only hold 99 elements before incorrectly reporting "error". Should check if (p->i >= 100) or use a separate counter.]
                printf("error\n");
            } else {
                struct node *new1 = (struct node*)malloc(sizeof(struct node));
                new1->data=i;
                new1->next=NULL;
                new1->i=p->i+1;
                p->next=new1;
                p=new1;
            }
        } else if(n==0){
            if(p->i==0) { // @@ [Error: When the stack is empty, p points to head, and head->i is 0, so this condition works. However, after popping the last element, p->i becomes 0, but the pop logic below does not correctly update p->i for the new top, causing subsequent pushes to have incorrect i values.]
                printf("error\n");
            } else {
                printf("%d\n",p->data);
                struct node *temp = head;
                while (temp->next!=p) {
                    temp = temp->next;
                }
                temp->next=NULL;
                p = temp;
                p->next = NULL; // @@ [Error: This line sets p->next to NULL, but p is now the new top (temp). This is redundant since temp->next was already set to NULL in the previous line. More importantly, it does not update p->i to reflect the new top's index, so subsequent pushes will have incorrect i values.]
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