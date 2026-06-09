#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int stack[101];

int main(int argc, char const *argv[])
{
    int top = 0, mod, flag = 1;
    do
    {
        scanf("%d", &mod);
        switch (mod)
        {
        case 1:
        {
            if (top == 100)
                printf("error ");
            else
                scanf("%d", &stack[++top]);
            break;
        }
        case 0:
        {
            if (top == 0)
                printf("error ");
            else
                printf("%d ", stack[top--]);
            break;
        }
        case -1:
        {
            flag--;
        }
        }
    } while (flag);
    return 0;
}

