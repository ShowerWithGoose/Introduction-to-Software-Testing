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
                        free(q); // @@ [When exponents are equal, the new node q is not freed in all code paths. In this case, after adding coefficients, q must be freed to avoid memory leak and double-free risk later. However, the more critical issue is that p0 is uninitialized when head is not NULL but the loop runs zero times (e.g., inserting at end), leading to undefined behavior. But the immediate error causing incorrect output is missing free(q) here.]
                        break;
                    }
                }
                if(p==NULL) {
                    if (p0 == NULL) { // @@ [If the list has only one node and we exit the loop immediately (p becomes NULL in first iteration), p0 remains uninitialized (still NULL from initial declaration). Then p0->next = q causes segmentation fault or undefined behavior. The variable p0 is used without being properly initialized in the case where the for-loop body never executes (i.e., when head is not NULL but we need to append at the end and the loop condition fails immediately).]
                        head->next = q;
                    } else {
                        p0->next = q;
                    }
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    free(head);
    free(q);
    head=q=NULL;
    return 0;
}