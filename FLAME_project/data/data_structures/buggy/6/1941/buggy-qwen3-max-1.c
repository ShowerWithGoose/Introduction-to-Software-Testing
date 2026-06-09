#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct zhan
{
    int a;
    zhan* next; // @@ [In C, using 'zhan*' before the typedef is complete is invalid; should use 'struct zhan*' or define the typedef properly. However, in this case, the typedef is defined correctly in standard C if the compiler supports it, but some strict compilers may require 'struct zhan*'. The real issue is that the struct tag and typedef name are the same, which is allowed in C, so this line is actually correct. The actual error comes from missing struct keyword in self-reference inside the struct definition in some strict C modes, but GCC usually allows this. However, the compilation error reported says 'unknown type name zhan' on line 9 of buggy code, which corresponds to this line. The problem is that within the struct definition, 'zhan' is not yet defined, so it must be 'struct zhan* next;'.]
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