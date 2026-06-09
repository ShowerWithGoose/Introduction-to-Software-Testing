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
                        free(q); // @@ [When exponents are equal, the new node q is not freed in all code paths. In this case, after adding the coefficient, q must be freed to avoid memory leak and double-free later. However, the bigger issue is that p0 is uninitialized when head is not NULL but the loop doesn't run (e.g., first insertion after head). But more critically, in the 'else if' branch, after updating p->coe, the code breaks but does not free(q), leading to a memory leak. However, the immediate cause of undefined behavior is that p0 may be used uninitialized.]
                        q = NULL;
                        break;
                    }
                }
                if(p==NULL) {
                    if (p0 == NULL) { // @@ [p0 is uninitialized when the inner for-loop never executes (i.e., when head is not NULL but the list has only one node and q->pow < head->pow). In that case, p0 remains NULL, and dereferencing it here causes undefined behavior. The reference program initializes r (equivalent to p0) properly by using a trailing pointer update in the loop condition. Here, p0 is only set inside the loop, so if the loop body never runs (e.g., head exists but q->pow <= head->pow and we fall through to p==NULL), p0 is still NULL from initialization, leading to segmentation fault when doing p0->next=q.]
                        head->next = q;
                    } else {
                        p0->next=q;
                    }
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    // @@ [The free() calls at the end are incorrect: only head and q are freed, but the entire linked list should be traversed and each node freed. Also, q may be NULL or already freed, causing double-free. However, the primary runtime error likely stems from the uninitialized p0 usage above.]
    free(head);
    free(q);
    head=q=NULL;
    return 0;
}