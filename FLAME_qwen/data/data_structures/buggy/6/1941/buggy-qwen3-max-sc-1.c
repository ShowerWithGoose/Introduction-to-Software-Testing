#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct zhan
{
    int a;
    zhan* next;
}zhan; // @@ [In C, when defining a struct type with typedef, the tag name and typedef name cannot be the same without using 'struct' keyword in the definition. This causes a compilation error because 'zhan' is used as both the struct tag and the typedef name in a way that's invalid in C (though valid in C++). The correct approach is to either use 'struct zhan' consistently or choose different names.]
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