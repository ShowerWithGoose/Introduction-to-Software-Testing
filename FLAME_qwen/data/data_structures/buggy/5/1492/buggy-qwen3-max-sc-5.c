/*本次作业由本人独立完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int coe;
    int pow;
    struct Node *next;
};
int num1[10050], num2[10050];
int main()
{
    int i=0, len1, len2, j;
    char c='a';
    while(c!='\n') {
        scanf("%d%d%c", &num1[i], &num1[i+1], &c);
        i+=2;
    }
    len1=i;
    i=0;
    c='a';
    while(c!='\n') {
        scanf("%d%d%c", &num2[i], &num2[i+1], &c);
        i+=2;
    }
    len2=i;
    struct Node *head, *p, *q, *p0;
    head=p=q=p0=NULL;
    for(i=0;i<len1;i+=2) {
        for(j=0;j<len2;j+=2) {
            if(head==NULL) {
                head=q=(struct Node *)malloc(sizeof(struct Node));
                q->coe=num1[i]*num2[j];
                q->pow=num1[i+1]+num2[j+1];
                q->next=NULL;
                continue;
            } else {
                q=(struct Node *)malloc(sizeof(struct Node));
                q->coe=num1[i]*num2[j];
                q->pow=num1[i+1]+num2[j+1];
                q->next=NULL;
                for(p=head;p!=NULL;p0=p,p=p->next) {
                    if(q->pow>p->pow) {
                        if(p==head) {
                            q->next=head;
                            head=q;
                            break;
                        } else {
                            q->next=p;
                            p0->next=q;
                            break;
                        }
                    } else if(q->pow==p->pow) {
                        p->coe+=q->coe;
                        free(q); // @@ [When exponents are equal, the new node q is not freed in all paths. In this case, after adding coefficients, q must be freed to avoid memory leak and double-free risk later. However, more critically, p0 is used uninitialized when inserting at head or when list has only one node.]
                        break;
                    }
                }
                if(p==NULL) {
                    p0->next=q; // @@ [p0 may be uninitialized here. If head was NULL initially, then in the first insertion, p0 remains NULL. Later, if a term needs to be appended at the end (p becomes NULL), p0 is still NULL from initialization, leading to dereferencing a NULL pointer. This causes undefined behavior (likely segmentation fault).]
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    free(head); // @@ [Only freeing head is insufficient. The entire linked list must be traversed and each node freed individually to prevent memory leaks. Also, if head is NULL, calling free(head) is safe, but if not, only the first node is freed.]
    free(q); // @@ [q may have been already freed inside the loop (e.g., when exponents match), leading to double-free. Also, q may point to a node that is already part of the list, so freeing it here is incorrect.]
    head=q=NULL;
    return 0;
}