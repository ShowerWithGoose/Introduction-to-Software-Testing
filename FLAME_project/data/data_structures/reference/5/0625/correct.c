#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pol
{
    int Coef;
    int Index;
    struct pol *Next;
} Poly;

Poly *Link_Create(int *len);

int main()
{
    int len_a = 0;
    int len_b = 0;
    Poly *list_a = Link_Create(&len_a);
    Poly *list_b = Link_Create(&len_b);
    Poly *p = list_a;
    Poly *list_c = (Poly *)malloc(sizeof(Poly));
    list_c->Next = NULL;
    Poly *r = list_c;
    int length = 0;

    while (p != NULL)
    {
        Poly *q = list_b;
        while (q != NULL)
        {
            Poly *s = (Poly *)malloc(sizeof(Poly));
            s->Coef = p->Coef * q->Coef;
            s->Index = p->Index + q->Index;
            s->Next = NULL;
            r->Next = s;
            r = s;
            q = q->Next;
        }
        p = p->Next;
    }

    p = list_c->Next;
    while (p != NULL)
    {
        Poly *q = NULL;
        q = p->Next;
        Poly *r = p;
        length++;
        while (q != NULL)
        {
            if (p->Index == q->Index)
            {
                p->Coef = q->Coef + p->Coef;
                r->Next = q->Next;
                free(q);
                q = r->Next;
                continue;
            }
            r = q;
            q = q->Next;
        }
        p = p->Next;
    }

    length -= 1;
    for (int i = 0; i < length; i++)
    {
        Poly *p = list_c->Next;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (p->Index < p->Next->Index)
            {
                int tmp = 0;
                tmp = p->Coef;
                p->Coef = p->Next->Coef;
                p->Next->Coef = tmp;
                tmp = p->Index;
                p->Index = p->Next->Index;
                p->Next->Index = tmp;
            }
            p = p->Next;
        }
    }

    list_c = list_c->Next;
    while (list_c != NULL)
    {
        if (list_c->Coef != 0)
        {
            printf("%d %d ", list_c->Coef, list_c->Index);
        }
        list_c = list_c->Next;
    }

    return 0;
}

Poly *Link_Create(int *len)
{
    char k = 0;
    Poly *list = (Poly *)malloc(sizeof(Poly));
    list->Next = NULL;
    Poly *p = list;
    scanf("%d %d", &p->Coef, &p->Index);
    k = (char)getchar();
    while (k == ' ')
    {
        Poly *s = (Poly *)malloc(sizeof(Poly));
        scanf("%d %d", &s->Coef, &s->Index);
        k = (char)getchar();
        s->Next = NULL;
        p->Next = s;
        p = s;
    }
    return list;
}
