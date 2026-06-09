#include <stdio.h>

#define Maxsize 100

int main()
{
    int s[Maxsize] = {0};
    int n, t, i = -1;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
        {
            scanf("%d", &t);
            if (i == Maxsize - 1)
            {
                printf("error ");
            }
            else
            {
                s[++i] = t;
            }
        }
        else if (n == 0)
        {
            if (i == -1)
                printf("error ");
            else
            {
                printf("%d ", s[i]);
                i--;
            }
        }
        else if (n == -1)
            break;
    }
    return 0;
}
