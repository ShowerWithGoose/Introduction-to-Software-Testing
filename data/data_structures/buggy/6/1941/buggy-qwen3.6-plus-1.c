#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct zhan
{
    int a;
    zhan* next; // @@ In C, the typedef alias 'zhan' is not yet defined inside the struct body. It must be declared as 'struct zhan* next;' to avoid a compilation error.
}zhan;
zhan* head=NULL;
int n = 0;
void ruzhan(int p)
{
    if (n == 100)
    {
        printf("error ");
        return;
    }
    n++;
    zhan* q = (zhan*)malloc(sizeof(zhan));
    q->a = p;
    q->next = head;
    head = q;
    return;
}
void chuzhan(void)
{
    if (n == 0)
    {
        printf("error ");
        return;
    }
    n--;
    printf("%d ", head->a);
    head = head->next;
    return;
}
int main()
{
    int k;
    while (scanf("%d", &k)&& k != -1)
    {
        switch(k)
        {
        case 1:
            scanf("%d", &k);
            ruzhan(k);
            break;
        case 0:
            chuzhan();
            break;
        }
    }

    return 0;
}