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
    top=(struct node*)malloc(sizeof(struct node)); // @@ [Memory leak and unnecessary allocation: 'top' is allocated but never used; the program uses 'p' as the top pointer instead.]
    head->next=NULL;
    head->i=0;
    head->data=0;
    p=q=head;
    while(scanf("%d",&n)!=EOF) {
        if(n==1) {
            scanf("%d",&i);
            if(p->i==100) {
                printf("error\n"); // @@ [Incorrect output format: should print "error " with a space, not "error\n". Also, after printing error, the program should continue processing, but using '\n' breaks expected output format.]
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
                printf("error\n"); // @@ [Incorrect output format: should print "error " with a space, not "error\n".]
            } else {
                printf("%d\n",p->data); // @@ [Incorrect output format: should print "%d " with a space, not "%d\n".]
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