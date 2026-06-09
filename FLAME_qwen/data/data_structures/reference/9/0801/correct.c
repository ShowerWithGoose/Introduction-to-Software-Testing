#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE_NUM (105)

typedef struct
{
    int n;
    struct line
    {
        struct
        {
            int x;
            int y;
        } left, right;
        struct line *next;
        int numNext;
    } l[MAX_LINE_NUM];
} lines;

void initLines(lines *l);
void readinLines(FILE *in, lines *l);
void prcsLines(lines *l);
void printLstLine(lines *l, FILE *out);

int prcsLine(lines *l, int curN);
bool isSamePoint(struct line *l1, struct line *l2);

int main()
{
    lines line;
    initLines(&line);
    readinLines(stdin, &line);
    prcsLines(&line);
    printLstLine(&line, stdout);
    return 0;
}

void initLines(lines *l)
{
    l->n = 0;
    for (int cnt = 0; cnt < MAX_LINE_NUM; cnt++)
    {
        l->l[cnt].next = NULL;
        l->l[cnt].numNext = -1;
    }
}

void readinLines(FILE *in, lines *l)
{
    fscanf(in, "%d", &(l->n));
    l->n = 0;
    while (fscanf(in, "%d %d %d %d", &(l->l[l->n].left.x), &(l->l[l->n].left.y), &(l->l[l->n].right.x), &(l->l[l->n].right.y)) != EOF)
    {
        (l->n)++;
    }
}

void prcsLines(lines *l)
{
    int n = l->n;
    for (int cnt = 0; cnt < n; cnt++)
    {
        if (l->l[cnt].numNext != -1)
        {
            continue;
        }
        prcsLine(l, cnt);

    }
}

int prcsLine(lines *l, int curN)
{
    struct line *cur = &(l->l[curN]);
    int n = l->n;
    int numNext = 0;
    for (int cnt = 0; cnt < n; cnt++)
    {
        if (isSamePoint(cur, &(l->l[cnt])))
        {
            cur->next = &(l->l[cnt]);
            numNext = prcsLine(l, cnt) + 1;
            l->l[curN].numNext = numNext;
            return numNext;
        }
    }
    numNext = 0;
    l->l[curN].numNext = numNext;
    return numNext;
}

bool isSamePoint(struct line *l1, struct line *l2)
{
    return (l1->right.x == l2->left.x && l1->right.y == l2->left.y);
}

void printLstLine(lines *l, FILE *out)
{
    int n = l->n;
    int maxLinesIndex = 0;
    for (int cnt = 0; cnt < n; cnt++)
    {
        maxLinesIndex = l->l[cnt].numNext > l->l[maxLinesIndex].numNext ? cnt : maxLinesIndex;
    }

    int len = l->l[maxLinesIndex].numNext + 1;
    int corX = l->l[maxLinesIndex].left.x;
    int corY = l->l[maxLinesIndex].left.y;

    fprintf(out, "%d %d %d", len, corX, corY);
}
