#include <stdio.h>

#define MAX_PN_ITEMS (400)
#define MAX_LINE_INPUT (160)

typedef struct
{
    int nItem;
    int co[MAX_PN_ITEMS];
    int ex[MAX_PN_ITEMS];
    int curMultiItem[MAX_PN_ITEMS];
} pn;

void polyReadin(FILE *in, pn *poly);
void polyMulti(pn *p1, pn *p2, pn *out);
void polyPrint(pn *poly, FILE *out);

int main()
{
    pn poly1, poly2, polyOut;
    polyReadin(stdin, &poly1);
    polyReadin(stdin, &poly2);
    polyMulti(&poly1, &poly2, &polyOut);
    polyPrint(&polyOut, stdout);
    return 0;
}

/*void polyReadin(FILE *in, pn *poly)
{
    char inputLine[MAX_LINE_INPUT];
    for (int cnt = 0; cnt < MAX_LINE_INPUT; cnt++)
    {
        inputLine[cnt] = '\0';
    }
    fgets(inputLine, MAX_LINE_INPUT, in);
    poly->nItem = 0;
    while (sscanf(inputLine, "%d %d", &poly->co[poly->nItem], &poly->ex[poly->nItem]) != EOF)
    {
        poly->nItem++;
    }
    for (int cnt = 0; cnt < poly->nItem; cnt++)
    {
        poly->curMultiItem[cnt] = 0;
    }
}*/

void polyReadin(FILE *in, pn *poly)
{
    char ch = ' ';
    poly->nItem = 0;
    while (ch != '\n')
    {
        fscanf(in, "%d %d%c", &poly->co[poly->nItem], &poly->ex[poly->nItem], &ch);
        poly->nItem++;
    }
    for (int cnt = 0; cnt < poly->nItem; cnt++)
    {
        poly->curMultiItem[cnt] = 0;
    }
}

void polyMulti(pn *p1, pn *p2, pn *out)
{
    int nItems1 = p1->nItem;
    int nItems2 = p2->nItem;
    int *ptnItemsOut = &out->nItem;
    *ptnItemsOut = 0;

    int curCo = 0;
    int curEx = -1;
    int curIndex = 0;
    int lastEx = -1;

    for (int cnt = 0; cnt < nItems1 * nItems2; cnt++)
    {
        int tempEx = -1;
        for (int cnt1 = 0; cnt1 < nItems1 ; cnt1++)
        {
            if (p1->curMultiItem[cnt1] == nItems2)
            {
                continue;
            }
            tempEx = p1->ex[cnt1] + p2->ex[p1->curMultiItem[cnt1]];
            curEx = tempEx >= curEx ? tempEx : curEx;
            curIndex = tempEx >= curEx ? cnt1 : curIndex;
        }

        curCo = p1->co[curIndex] * p2->co[p1->curMultiItem[curIndex]];
        (p1->curMultiItem[curIndex])++;

        if (curEx == lastEx)
        {
            (*ptnItemsOut)--;
            out->co[*ptnItemsOut] += curCo;
        }
        else
        {
            if (out->co[*ptnItemsOut - 1] == 0 && *ptnItemsOut > 0)
            {
                (*ptnItemsOut)--;
            }
            out->ex[*ptnItemsOut] = curEx;
            out->co[*ptnItemsOut] = curCo;
        }

        lastEx = curEx;
        curEx = -1;
        (*ptnItemsOut)++;
    }
}

void polyPrint(pn *poly, FILE *out)
{
    int nItems = poly->nItem;
    for (int cnt = 0; cnt < nItems; cnt++)
    {
        fprintf(out, "%d %d ", poly->co[cnt], poly->ex[cnt]);
    }
}
