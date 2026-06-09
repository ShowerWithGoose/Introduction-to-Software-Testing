#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 1000
struct sqstack
{
    int data[maxsize];
    int top;
};
struct sqstack s;
int main()
{
    s.top = -1;
    int m, e;
    while ((scanf("%d", &m)) != EOF)
    {
        switch (m)
        {
        case 1:
            scanf("%d", &e);
            if (s.top >= maxsize)
            {
                printf("error ");
            }
            else
            {
                s.top++;
                s.data[s.top] = e;
            }
            break;
        case 0:
            if (s.top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", s.data[s.top]);
                s.top--;
            }
            break;
        case -1:
            break;
        }
    }
    return 0;
}
