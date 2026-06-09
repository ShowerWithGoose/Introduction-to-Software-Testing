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
    head0 = (struct Node *)malloc(sizeof(struct Node)); // @@ [Error: head0 is initialized to a non-NULL dummy node, but the logic inside the loop checks `if(head0 == NULL)` to insert the first real node. This causes the first calculated term to be skipped/lost because head0 is never NULL. Additionally, this dummy node is never removed or handled, leading to garbage output or missing terms.]
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
                    if(r == NULL) s->next = q; // @@ [Error: This check `if(r == NULL)` is inside the loop condition `r != NULL`, so it will never be true during the loop execution. It should be outside the loop to handle appending to the end if the term wasn't inserted or merged.]
                }
                
            }
        }
    } while (c != '\n');
    for(p = head0; p != NULL; p = p->next){
        if(p->coe != 0) // @@ [Error: The problem states only non-zero terms should appear in input, and typically multiplication results should also suppress zero coefficients (e.g., if terms cancel out). The reference program doesn't explicitly show this filter in the output loop but the logic implies valid terms. However, the main issue here is the dummy node at head0. If we fix the initialization, we might still print zero coefficients if they result from addition. But strictly speaking, the prompt's expected output `120 2000000000` vs buggy `120 2000000000 0 0` suggests the dummy node or uninitialized memory is printing garbage or zero terms. Given the dummy node allocation at line 25, `head0` points to garbage/uninitialized data. The loop prints it. We need to skip zero coefficients or fix the list structure.]
        printf("%d %d ", p->coe, p->pow);
    }
    return 0;
}