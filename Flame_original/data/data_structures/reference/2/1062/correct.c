#include <stdio.h>
#include <string.h>
struct element
{
    int num;
    char sig;
} equa[100], tmp[100], re[100];
int main()
{
    int i, j, k, l;
    scanf(" %d %c", &equa[0].num, &equa[0].sig);
    for (i = 1; equa[i - 1].sig != '='; i++)
    {
        scanf(" %d %c", &equa[i].num, &equa[i].sig);
    }
    k = i;
    for (i = 0, j = 0; i < k; i++, j++)
    {
        tmp[j] = equa[i];
        if (equa[i].sig == '*')
        {
            tmp[j].num = equa[i + 1].num * tmp[j].num;
            equa[i + 1].num = tmp[j].num;
            j--;
        }
        if (equa[i].sig == '/')
        {
            tmp[j].num = tmp[j].num / equa[i + 1].num;
            equa[i + 1].num = tmp[j].num;
            j--;
        }
        //        printf("%d %d\n", j, tmp[j].num);
    }
    /*for (i = 0; i < j; i++)
    {
        printf("%d%c", tmp[i].num, tmp[i].sig);
    }*/
    for (i = 0, l = 0; i < j && i < k; i++, l++)
    {
        re[l] = tmp[i];
        if (tmp[i].sig == '+')
        {
            re[l].num = tmp[i + 1].num + re[l].num;
            tmp[i + 1].num = re[l].num;
            l--;
        }
        // printf("%d\n", tmp[j].num);
        if (tmp[i].sig == '-')
        {
            re[l].num = re[l].num - tmp[i + 1].num;
            tmp[i + 1].num = re[l].num;
            l--;
        }
    }
    printf("%d\n", re[l - 1].num);
    return 0;
}

