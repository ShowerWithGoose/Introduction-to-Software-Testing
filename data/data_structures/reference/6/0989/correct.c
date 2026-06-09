#include <stdio.h>
#include <ctype.h>  //字符类型判断
#include <string.h> //字符串处理
#include <stdlib.h> //qsort,rand,bsearch
int main()
{
    int sh[100], top = -1, x;
    while (scanf("%d", &x) != EOF)
    {
        if (x == -1)
        {
            break;
        }
        else if (x == 1)
        {
            if (top == 100)
            {
                printf("error ");
            }
            else
            {
                scanf("%d", &sh[++top]);
            }
        }
        else if (x == 0)
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", sh[top--]);
            }
        }
    }
    return 0;
}
