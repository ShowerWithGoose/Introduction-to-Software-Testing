# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

struct Node {
    int coe;
    int pow;
    struct Node *next;
};
typedef struct Node *Nodeptr;
typedef struct Node Node;
struct Node *head1, *head2, *p, *q, *p0, *q0;
int main() {
    int a, b;
    char s = 'l';

    while (s != '\n') {
        scanf("%d%d%c", &a, &b, &s);
        q = (struct Node *) malloc(sizeof(struct Node));
        q->coe = a;
        q->pow = b;
        q->next = NULL;
        if (head1 == NULL)
            head1 = p = q;
        else {
            p->next = q;
            p = p->next;
        }
    }

    s = 'l';
    while (s != '\n') {
        scanf("%d%d%c", &a, &b, &s);
        for (p = head1; p != NULL; p = p->next) {
            int x=a,y=b;
            x *= p->coe;
            y += p->pow;
            q = (struct Node *) malloc(sizeof(struct Node));
            q->coe = x;
            q->pow = y;
            q->next = NULL;
            if (head2 == NULL) {
                head2 = q;
            } else {
                for (q0 = head2; q0 != NULL;p0 = q0,q0 = q0->next) {
                    if (y > q0->pow) {
                        q->next = q0;
                        p0->next = q;
                        break;
                    } else if (y == q0->pow) {
                        q0->coe += x;
                        break;
                    }
                }
                if (q0 == NULL) p0->next = q;
            }

        }
    }
    for (p = head2; p != NULL; p = p->next)
        printf("%d %d ", p->coe, p->pow);
    return 0;
}
