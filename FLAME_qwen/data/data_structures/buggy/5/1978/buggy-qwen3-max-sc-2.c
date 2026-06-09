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
    head0 = (struct Node *)malloc(sizeof(struct Node)); // @@ [head0 is initialized with a dummy node that is never used properly; this causes the first term of the result to be inserted after a useless node, and also leads to uninitialized fields (coe, pow) in this dummy node which may cause undefined behavior or incorrect output]
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
                    if(r == NULL) s->next = q; // @@ [This condition is unreachable because the loop condition is 'r != NULL'; when r becomes NULL, the loop exits, so this line never executes. As a result, new terms with the smallest exponent are never appended to the end of the list.]
                }
                
            }
        }
    } while (c != '\n');
    for(p = head0; p != NULL; p = p->next){
        printf("%d %d ", p->coe, p->pow);
    }
    return 0;
}