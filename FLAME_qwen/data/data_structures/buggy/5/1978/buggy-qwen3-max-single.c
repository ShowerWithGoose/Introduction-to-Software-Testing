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
    head0 = (struct Node *)malloc(sizeof(struct Node)); // @@ [head0 is initialized with an empty dummy node, but it should be NULL to represent an empty result polynomial. This causes the first term to be inserted incorrectly and leads to output of an extra zero-coefficient term or incorrect structure.]
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
                    if(r == NULL) s->next = q; // @@ [This line is unreachable because the loop condition is 'r != NULL', so when r becomes NULL, the loop exits and this statement never executes. Thus, new terms with lowest exponent won't be appended correctly.]
                }
                
            }
        }
    } while (c != '\n');
    for(p = head0; p != NULL; p = p->next){
        printf("%d %d ", p->coe, p->pow);
    }
    return 0;
}