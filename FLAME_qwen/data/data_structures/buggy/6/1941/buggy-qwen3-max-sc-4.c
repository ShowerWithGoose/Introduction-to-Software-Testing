#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct zhan
{
    int a;
    zhan* next;
}zhan; // @@ [In C, using 'zhan' as a type name inside its own definition is invalid because the typedef is not yet complete at that point. This causes a compilation error. The correct approach is to use 'struct zhan*' instead of 'zhan*' in the struct definition.]
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