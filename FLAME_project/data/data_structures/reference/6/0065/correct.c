#include <stdio.h>
char full(int *l);
char empty(int *l);
int main()
{
    int stuck[110] = {0};
    int flag = 0, p = -1;
    char check;
    while (1)
    {
        scanf("%d", &flag);
        if (flag == 1)
        {
            check = full(stuck);
            if (check == 'Y')
                printf("error ");
            else
                scanf("%d", &stuck[++p]);
        }
        else if(flag == 0)
        {
            check = empty(stuck);
            if (check == 'Y')
                printf("error ");
            else
            {
                printf("%d ", stuck[p]);
                stuck[p--] = 0;
            }
        }
        if(flag == -1)
            break;
    }
}
char full(int *l)
{
    if (l[99] != 0)
        return 'Y';
    else
        return 'N';
}
char empty(int *l)
{
    if (l[0] != 0)
        return 'N';
    else
        return 'Y';
}
