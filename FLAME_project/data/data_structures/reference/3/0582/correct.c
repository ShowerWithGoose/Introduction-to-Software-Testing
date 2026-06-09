
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    char a[10000] = { 0 };int cnt = 0;

    gets(a);int i = 0;int k = 0;int len = strlen(a);
    if (a[0] != '-')
    {
        for (;(a[i] != '.') && i < len;i++);
        if (a[i - 1] == '0')//小数
        {
            for (k = i + 1;a[k] == '0';k++);

            if (k == len - 1)//0.000002
            {
                printf("%ce-%d", a[k], k - 1);

            }
            else if (k != len - 1)
            {
                printf("%c.", a[k]);int len2 = k;
                for (k = k + 1;k <= len - 1;k++) printf("%c", a[k]);
                printf("e-%d", len2-1);

            }
        }
        else
        {
            if (len == 1)printf("%ce0", a[0]);
            else {
                printf("%c.", a[0]);
                for (int m = 1;m <= i - 1;m++) printf("%c", a[m]);
                for (int m = i + 1;m < len;m++) printf("%c", a[m]);
                printf("e%d", i - 1);
            }
        }
    }
    else {
        
        for (int i = 0;i < len - 1;i++)
        {
            a[i] = a[i + 1];
        }a[len-1] = '\0';
        int i = 0;len = len - 1;
        for (;(a[i] != '.') && i < len;i++);
        if (a[i - 1] == '0')//小数
        {
            for (k = i + 1;a[k] == '0';k++);

            if (k == len - 1)//0.000002
            {
                printf("-%ce-%d", a[k], k - 1);

            }
            else if (k != len - 1)
            {
                printf("-%c.", a[k]);int len2 = len - k;
                for (k = k + 1;k <= len - 1;k++) printf("%c", a[k]);
                printf("e-%d", len2);

            }
        }
        else
        {
            if (len == 1)printf("-%ce0", a[0]);
            else {
                printf("-%c.", a[0]);
                for (int m = 1;m <= i - 1;m++) printf("%c", a[m]);
                for (int m = i + 1;m < len;m++) printf("%c", a[m]);
                printf("e%d", i - 1);
            }
        }







    }
    return 0;
}



