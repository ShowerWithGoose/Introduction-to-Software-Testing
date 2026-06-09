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
            if(p->i==100) {
                printf("error\n"); // @@ [The problem requires outputting "error " (with a space) and continuing, but this prints "error\n" (with a newline). Also, the stack state should not change on error, which is handled correctly here by not pushing, but the output format is wrong.]
            } else {
                struct node *new1 = (struct node*)malloc(sizeof(struct node));
                new1->data=i;
                new1->next=NULL;
                new1->i=p->i+1;
                p->next=new1;
                p=new1;
            }
        } else if(n==0){
            if(p->i==0) {
                printf("error\n"); // @@ [The problem requires outputting "error " (with a space), but this prints "error\n" (with a newline).]
            } else {
                printf("%d\n",p->data); // @@ [The problem requires outputting the popped element followed by a space (" %d "), not a newline. This causes the output to be vertical instead of horizontal.]
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