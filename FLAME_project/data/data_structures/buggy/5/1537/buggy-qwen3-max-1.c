#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int xs;
    int zs;
    struct node *next;
};

int main()
{
    int a, b;
    char c;
    struct node *head1, *p1, *q1;
    head1 = p1 = NULL;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        q1 = (struct node*)malloc(sizeof(struct node));
        q1->xs = a;
        q1->zs = b;
        q1->next = NULL;
        if(head1 == NULL)
        head1 = p1 = q1;
        else
        {
            p1->next = q1;
            p1 = p1->next;
        }
    }while(c != '\n');
    struct node *head2, *p2, *q2;
    head2 = p2 = NULL;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        q2 = (struct node*)malloc(sizeof(struct node));
        q2->xs = a;
        q2->zs = b;
        q2->next = NULL;
        if(head2 == NULL)
        head2 = p2 = q2;
        else
        {
            p2->next = q2;
            p2 = p2->next;
        }
    }while(c != '\n');
    //input
    //printf("OK\n");
    struct node *p0, *p00, *p3, *q3, *head3, *bfr;
    int ansxs, anszs;
    head3 = p3 = NULL;
    for(p0 = head1; p0 != NULL; p0 = p0->next)
    {
        for(p00 = head2; p00 != NULL; p00 = p00->next)
        {
            ansxs = p0->xs * p00->xs;
            anszs = p0->zs + p00->zs;
            q3 = (struct node*)malloc(sizeof(struct node));
            if(head3 == NULL)
            {
                q3->xs = ansxs;
                q3->zs = anszs;
                q3->next = NULL;
                head3 = p3 = q3;
            }
            else
            {
                for(p3 = head3; p3 != NULL; bfr = p3, p3 = p3->next)
                {
                    if(anszs == p3->zs)
                    {
                        p3->xs += ansxs;
                        free(q3);
                        break;
                    }

                    if(anszs > p3->zs)
                    {
                        q3->xs = ansxs;
                        q3->zs = anszs;
                        q3->next = p3;
                        if(p3 == head3)
                        {
                            head3 = q3;
                        }
                        else
                        {
                            bfr->next = q3;
                        }
                        break;
                    }
                    if(p3->next == NULL)
                    {
                        q3->xs = ansxs;
                        q3->zs = anszs;
                        q3->next = NULL;
                        p3->next = q3;
                        break;
                    }
                }
            }
        }
    }
    for(p3 = head3; p3 != NULL; p3 = p3->next)
    {
        printf("%d %d ", p3->xs, p3->zs);
    }
    return 0;
}