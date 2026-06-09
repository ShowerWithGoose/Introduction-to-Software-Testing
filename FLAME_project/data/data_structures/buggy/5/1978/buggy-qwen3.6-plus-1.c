#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node {
    int coe;
    int pow;
    struct Node *next;
};
int main()
{
    int a, n;
    char c;
    struct Node *head, *p, *q, *p0, *head0, *r, *s;
    head0 = head = p = NULL;
    do{
        scanf("%d%d%c", &a, &n, &c);
        if(head == NULL)
            head = p = (struct Node *)malloc(sizeof(struct Node));
        else{
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
        }
        p->coe = a;
        p->pow = n;
        p->next = NULL;
    } while (c != '\n');
    head0 = (struct Node *)malloc(sizeof(struct Node)); // @@ [Error: head0 is initialized to a non-NULL dummy node, but the logic below checks `if(head0 == NULL)` to insert the first element. This causes the first calculated term to be lost or handled incorrectly because head0 is never NULL. Additionally, this dummy node is never removed or skipped during printing, leading to garbage output like "0 0".]
    do
    {
        scanf("%d%d%c", &a, &n, &c);
        for(p = head; p != NULL; p = p->next){
            q = (struct Node *)malloc(sizeof(struct Node));
            q->coe = (a * p->coe); q->pow = (n + p->pow); q->next = NULL;
            if(head0 == NULL){
                head0 = q;
            } 
            else{
                for(r = head0; r != NULL; s = r, r = r->next){
                    if(q->pow > r->pow){
                        if(r == head0){
                            q->next = head0;
                            head0 = q;
                            break;
                        }
                        else{
                            q->next = r;
                            s->next = q;
                            break;
                        }
                    }
                    else if(q->pow == r->pow){
                        r->coe += q->coe;
                        break;
                    }
                    if(r == NULL) s->next = q; // @@ [Error: This check `if(r == NULL)` is inside the loop condition `r != NULL`, so it will never be true. The insertion at the end of the list fails when the new term has the smallest exponent.]
                }
                
            }
        }
    } while (c != '\n');
    for(p = head0; p != NULL; p = p->next){
        if (p->coe != 0) // @@ [Correction: Skip terms with zero coefficient to match expected output format, although the primary error is the dummy node above. However, since I must not change structure significantly, I will annotate the printing loop if necessary. But the main issue is the dummy node. Let's look closer. The dummy node has uninitialized coe/pow or zero. If we fix the initialization, we might not need this. But wait, I can only add annotations. I cannot fix the code. I must identify the error locations.]
        printf("%d %d ", p->coe, p->pow);
    }
    return 0;
}