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
                        free(q); // @@ [When exponents are equal, the newly allocated node q is merged into existing node p, but q is not freed, leading to memory leak. However, the critical error is later: after merging, q becomes dangling and may be freed again at end. But more critically, in this case, q should be freed immediately after merging to avoid double-free later.]
                        break;
                    }
                }
                if(p==NULL) {
                    p0->next=q;
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    free(head); // @@ [Only head is freed, but the entire linked list is not traversed and freed properly. This causes memory leak, but not double-free. However, the real double-free comes from: when a term is merged (same exponent), q is not freed, but later 'free(q)' at the end tries to free a possibly already-freed or invalid pointer. Also, q may point to a node that was already inserted and then merged, so freeing q unconditionally is wrong.]
    free(q); // @@ [This line causes double-free: if during insertion a node q was merged (i.e., same exponent found), then q was not inserted into the list and should be freed immediately (which wasn't done). But if it was inserted, then it's part of the list and will be freed when traversing the list — but here we don't traverse. Worse: q points to the last allocated node, which might have been merged and thus already logically discarded (but not freed), OR it might be in the list. In the test case, only one term is produced, so q points to the only node. Then 'free(head)' frees it, and 'free(q)' frees the same address again → double free.]
    head=q=NULL;
    return 0;
}