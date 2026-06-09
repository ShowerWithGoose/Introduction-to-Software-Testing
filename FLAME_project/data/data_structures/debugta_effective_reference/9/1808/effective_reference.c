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
        int cnt;
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
    for (int i = 0; i < MAX_LINE_NUM; i++)
    {
        l->l[i].next = NULL;
        l->l[i].cnt = -1;
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
    for (int i = 0; i < n; i++)
    {
        if (l->l[i].cnt != -1)
        {
            continue;
        }
        prcsLine(l, i);

    }
}

int prcsLine(lines *l, int curN)
{
    struct line *cur = &(l->l[curN]);
    int n = l->n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isSamePoint(cur, &(l->l[i])))
        {
            cur->next = &(l->l[i]);
            cnt = prcsLine(l, i) + 1;
            l->l[curN].cnt = cnt;
            return cnt;
        }
    }
    cnt = 0;
    l->l[curN].cnt = cnt;
    return cnt;
}

bool isSamePoint(struct line *l1, struct line *l2)
{
    return (l1->right.x == l2->left.x && l1->right.y == l2->left.y);
}

void printLstLine(lines *l, FILE *out)
{
    int n = l->n;
    int max_tiao = 0;
    for (int i = 0; i < n; i++)
    {
        max_tiao = l->l[i].cnt > l->l[max_tiao].cnt ? i : max_tiao;
    }

    int max_line = l->l[max_tiao].cnt + 1;
    int corX = l->l[max_tiao].left.x;
    int corY = l->l[max_tiao].left.y;

    fprintf(out, "%d %d %d", max_line, corX, corY);
}
