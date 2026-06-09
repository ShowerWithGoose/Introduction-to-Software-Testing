#include <stdio.h>

int a[103];

int main()
{
    int x, y;
    int flag = 0;
    while (scanf("%d", &x) != EOF)
    {
        if (x == 1)
        {
            scanf("%d", &y);
            if (flag != 100)
            {
                a[flag] = y;
                flag++;
            }
            else
            {
                printf("error ");
            }
        }
        else if (x == 0)
        {
            if (flag == 0)
            {
                printf("error ");
            }
            else
            {
                flag--;
                printf("%d ", a[flag]);
            }
        }
        else
        {
            return 0;
        }
    }
}
