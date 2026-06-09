#include <stdio.h>
int judge(char a, char b)
{
    if ((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') || (a >= '0' && a <= '9' && b >= '0' && b <= '9') || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char a[3];
    int i;
    while ((a[0] = getchar()) != EOF)
    {
    node1:
        a[1] = getchar();
        if (a[1] == EOF)
        {
            printf("%c", a[0]);
            break;
        }
        else if (a[1] == '-')
        {
            a[2] = getchar();
            i = 0;
            if (judge(a[0], a[2]) == 0)
            {
                printf("%c%c", a[0], a[1]);
                a[0] = a[2];
                goto node1;
            }
            while (a[0] + i < a[2])
            {
                printf("%c", a[0] + i);
                i++;
            }
            a[0] = a[2];
            goto node1;
        }
        else if (a[1] != '-')
        {
            printf("%c", a[0]);
            a[0] = a[1];
            goto node1;
        }
    }
    return 0;
}


