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
    top=(struct node*)malloc(sizeof(struct node)); // @@ [Memory leak and unused variable: 'top' is allocated but never used; the program uses 'head' and 'p' for stack operations instead. Also, this unnecessary allocation may contribute to resource issues but is not the primary cause of the observed error.]
    head->next=NULL;
    head->i=0;
    head->data=0;
    p=q=head;
    while(scanf("%d",&n)!=EOF) {
        if(n==1) {
            scanf("%d",&i);
            if(p->i==100) {
                printf("error\n"); // @@ [Incorrect output format: The problem requires outputting "error " (with a space, not newline). Using '\n' instead of space causes mismatch with expected output format.]
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
                printf("error\n"); // @@ [Incorrect output format: Should print "error " with a space, not a newline. This causes the output to not match the expected format.]
            } else {
                printf("%d\n",p->data); // @@ [Incorrect output format: Should print "%d " with a space after the number, not a newline. This breaks the required output format.]
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