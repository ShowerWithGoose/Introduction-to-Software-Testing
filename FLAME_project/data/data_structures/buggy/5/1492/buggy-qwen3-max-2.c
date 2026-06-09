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
                        free(q); // @@ [When exponents are equal, the newly allocated node 'q' is not freed after merging its coefficient into an existing node, causing a memory leak. However, the critical error is later: attempting to free 'q' unconditionally at the end even when it may have been already freed or never allocated in some paths. But more importantly, in this specific test case, only one term is generated, so 'q' is set to the only node and then later freed twice: once here (if merged) — but in this test case there's no merge — and then again at the end. Actually, in this test case, there's only one product term, so head is set once, and then at the end both 'head' and 'q' point to the same node. Thus, freeing both causes double free.]
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
    free(head);
    free(q); // @@ [If the result polynomial has only one term (as in the test case), then 'head' and 'q' point to the same allocated node. Freeing both leads to a double free, which causes the runtime error "free(): double free detected in tcache 2". Additionally, if there are multiple terms, 'q' points to the last allocated node, but intermediate nodes are not freed, and 'q' might even be NULL in edge cases (though not here). The proper way is to traverse and free the entire linked list, not just 'head' and 'q'.]
    head=q=NULL;
    return 0;
}