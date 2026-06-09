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
                        free(q); // @@ [Memory leak fix: q was allocated but not freed when merged with existing node]
                        break;
                    }
                }
                if(p==NULL) {
                    p0->next=q;
                } else if (q != head && q->next != NULL && p != NULL && p->pow != q->pow) { 
                     // This logic is complex. The main issue causing Runtime Error (double free or corruption) usually stems from incorrect pointer management or freeing nodes that are still linked or double freeing.
                     // However, looking at the specific error "free(): double free detected", let's look at the end of main.
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    // The original code attempts to free head and q. 
    // 1. 'q' might have been freed inside the loop if it was merged (though the original code didn't free it, causing a leak, not a double free).
    // 2. If 'q' was appended to the list, it is part of the list starting at 'head'.
    // 3. Freeing 'head' only frees the first node. The rest of the list is leaked.
    // 4. Freeing 'q' separately is dangerous. If 'q' is the same as 'head' (first node), it's a double free if we traversed and freed head? No, head is just one node.
    // But wait, if q was merged into an existing node, the original code DID NOT free q. So q is dangling? No, q is just a pointer to a malloc'd block that is now lost (leak).
    // At the end: free(head) frees the first node. free(q) frees the last allocated node.
    // If the list has only one node, head == q. Then free(head) and free(q) is a double free. This matches the error!
    free(head); // @@ [Double free error: if the polynomial result has only one term, head equals q. Freeing both causes double free. Also, this does not correctly free the entire linked list, leading to memory leaks or crashes if list > 1 node and q is elsewhere.]
    free(q); // @@ [Double free error: see above. Additionally, proper cleanup requires iterating through the entire list to free all nodes.]
    head=q=NULL;
    return 0;
}