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
                        free(q); // @@ [Memory leak: when coefficients are merged, the newly allocated node q is not freed, causing a memory leak. While not strictly a double free, it's bad practice. However, the main error is below.]
                        break;
                    }
                }
                if(p==NULL) {
                    p0->next=q;
                } else if (q->pow == p->pow) {
                     // The logic above handles insertion or merge. 
                     // If merged, q was freed (if we added the fix). 
                     // If inserted, q is now part of the list.
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    // The original code attempts to free head and q separately. 
    // q might be part of the list (if it was the last inserted node) or already freed (if merged).
    // If q is part of the list, freeing it here and then potentially iterating or freeing other nodes causes issues.
    // More importantly, if q was merged into an existing node, it was freed in the loop (with my fix) or leaked (without).
    // If q was inserted, it is inside the linked list. Freeing 'head' usually implies freeing the whole list in student code, 
    // but here only head is freed. Then q is freed. If q != head, this is a double free if q is still reachable or invalidates heap state.
    // Actually, the specific error "double free detected" often comes from freeing a node that is still in the list or freeing the same pointer twice.
    // In the case where only one term exists, head == q. free(head) frees it. free(q) frees it again. Double free.
    free(head); // @@ [Runtime Error: Double free. If the list has only one node, head == q. Freeing head then q frees the same memory twice. Also, generally, one should free the entire linked list properly, not just head and q.]
    free(q); // @@ [Runtime Error: Double free. See above. If head == q, this is a double free. If q was merged and freed earlier, this is a use-after-free/double free. If q is in the list but not head, freeing it here corrupts the list structure if other nodes point to it, or is just incorrect memory management.]
    head=q=NULL;
    return 0;
}