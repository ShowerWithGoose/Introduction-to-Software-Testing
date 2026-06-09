#include <stdio.h>
#include <stdlib.h>

typedef struct _line
{
    int x1, y1, x2, y2;
    struct _line *n1, *n2;
} line;

int main()
{
    line *ln[9999] = {NULL};
    int cnt, i, j;
    int x1, y1, x2, y2;
    line *pc, *pn;
    int maxn, maxlx, maxly;

    scanf("%d", &cnt);
    for(i = 0; i < cnt; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ln[i] = (line*)malloc(sizeof(line));
        ln[i]->x1 = x1;
        ln[i]->y1 = y1;
        ln[i]->x2 = x2;
        ln[i]->y2 = y2;
        ln[i]->n1 = NULL;
        ln[i]->n2 = NULL;
    }

    for (i = 0; ln[i]; i++)
    for (j = i+1; ln[j]; j++)
    {
        if (ln[i]->x1 == ln[j]->x1 && ln[i]->y1 == ln[j]->y1) {
            ln[i]->n1 = ln[j];
            ln[j]->n1 = ln[i];
        } else if (ln[i]->x1 == ln[j]->x2 && ln[i]->y1 == ln[j]->y2) {
            ln[i]->n1 = ln[j];
            ln[j]->n2 = ln[i];
        } else if (ln[i]->x2 == ln[j]->x1 && ln[i]->y2 == ln[j]->y1) {
            ln[i]->n2 = ln[j];
            ln[j]->n1 = ln[i];
        } else if (ln[i]->x2 == ln[j]->x2 && ln[i]->y2 == ln[j]->y2) {
            ln[i]->n2 = ln[j];
            ln[j]->n2 = ln[i];
        }
    }

    for(i = 0; i < cnt; i++)
    {
        if (ln[i]->n1 == NULL && ln[i]->n2 == NULL)
        {
            j = 1;
            if (j > maxn)
            {
                maxn = j;
                maxlx = ln[i]->x1;
                maxly = ln[i]->y1;
            }
        }
        else if (ln[i]->n1 == NULL || ln[i]->n2 == NULL)
        {
            pc = ln[i];
            pn = (ln[i]->n1 == NULL) ? ln[i]->n2 : ln[i]->n1;
            j = 2;
            while (1) {
                //printf("%d %d %d %d %d %d\n", pc->x1, pc->y1, pn->n1->x1, pn->n1->y1, pn->n2->x1, pn->n2->y1);
                if (pn->n1 == NULL || pn->n2 == NULL) {
                    break;
                } else if (pc == pn->n1) {
                    pc = pn;
                    pn = pn->n2;
                    j++;
                } else if (pc == pn->n2) {
                    pc = pn;
                    pn = pn->n1;
                    j++;
                }
            }
            if (j > maxn)
            {
                maxn = j;
                if (ln[i]->n1 == NULL) {
                    maxlx = ln[i]->x1;
                    maxly = ln[i]->y1;
                } else if (ln[i]->n2 == NULL) {
                    maxlx = ln[i]->x2;
                    maxly = ln[i]->y2;
                }
            } else if(j == maxn)
            {
                if (ln[i]->n1 == NULL && ln[i]->x1 < maxlx) {
                    maxlx = ln[i]->x1;
                    maxly = ln[i]->y1;
                } else if (ln[i]->n2 == NULL && ln[i]->x2 < maxlx) {
                    maxlx = ln[i]->x2;
                    maxly = ln[i]->y2;
                }
            }
        }
    }

    printf("%d %d %d", maxn, maxlx, maxly);

    return 0;
}

