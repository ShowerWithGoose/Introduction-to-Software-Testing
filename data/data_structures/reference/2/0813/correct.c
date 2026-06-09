#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int pre[10000] = {0}, i, j = 1, md[2] = {0}, num;
    char sign[10000] = {'\0'}, cc[2] = {'\0'}, fig;
    for (i = 1;; i++)
    {
        scanf("%d %c", &num, &fig);
        if (fig == '=')
        {
            pre[j] = num;
            sign[j] = fig;
            j++;
            break;
        }
        else if (fig == '-' || fig == '+')
        {
            pre[j] = num;
            sign[j] = fig;
            j++;
        }
        else if (fig == '*' || fig == '/')
        {
            cc[0] = fig;
            md[0] = num;
            while (cc[0] == '*' || cc[0] == '/')
            {
                scanf("%d %c", &md[1], &cc[1]);
                if (cc[0] == '*')
                    md[0] = md[0] * md[1];
                else if (cc[0] == '/')
                    md[0] = md[0] / md[1];
                cc[0] = cc[1];
            }
            pre[j] = md[0];
            sign[j] = cc[0];
            j++;
            if (cc[0] == '=')
            {
                break;
            }
        }
    }
    for (i = 1; i < j; i++)
    {
        if (sign[i] == '+')
            pre[i + 1] = pre[i + 1] + pre[i];
        if (sign[i] == '-')
            pre[i + 1] = pre[i] - pre[i + 1];
    }
    printf("%d", pre[i - 1]);
    return 0;
}


