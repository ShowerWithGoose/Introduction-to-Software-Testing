#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct add
{
    int time;
    int square;
    int timeadd;
    int flag;
    struct add *next;
};
int main()
{
    int i, j, t, s;
    char c;
    struct add *head = NULL, *p = NULL, *q = NULL, *r = NULL, *k = NULL, *m = NULL;
    do
    {
        scanf("%d%d%c", &t, &s, &c);

        if (head == NULL)
        {
            q = (struct add *)malloc(sizeof(struct add));
            q->time = t;
            q->square = s;
            q->timeadd = 0;
            q->flag = 1;
            q->next = NULL;
            p = q;
            head = q;
        }
        else
        {
            q = (struct add *)malloc(sizeof(struct add));
            q->time = t;
            q->square = s;
            q->timeadd = 0;
            q->flag = 1;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    } while (c != '\n');
    do
    {
        scanf("%d%d%c", &t, &s, &c);
        for (p = head; p != NULL; p = p->next)
        {
            if (p->flag)
            {
                for (q = head; q != NULL; q = q->next)
                {
                    if (s + p->square == q->square)
                    {
                        q->timeadd += t * (p->time);
                        break;
                    }
                }
                if (q == NULL)
                {
                    for (r = head; r->square > (s + p->square) && r != NULL; k = r, r = r->next)
                        ;
                    if (r == head)
                    {
                        k = (struct add *)malloc(sizeof(struct add));
                        k->square = s + p->square;
                        k->time = 0;
                        k->timeadd = t * (p->time);
                        k->flag = 0;
                        k->next = head;
                        head = k;
                    }
                    else
                    {
                        m = (struct add *)malloc(sizeof(struct add));
                        m->square = s + p->square;
                        m->time = 0;
                        m->timeadd = t * (p->time);
                        m->flag = 0;
                        m->next = k->next;
                        k->next = m;
                    }
                }
            }
        }
    } while (c != '\n');
    for (p = head; p != NULL; p = p->next)
    {
        if (p->timeadd != 0)
        {
            printf("%d %d ", p->timeadd, p->square);
        }
    }
    return 0;
}
