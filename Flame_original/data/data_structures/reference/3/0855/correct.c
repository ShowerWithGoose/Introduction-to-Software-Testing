#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[105];
int main()
{
    gets(str);
    int len = strlen(str);
    int i;
    int P_Dot=0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == '.')
            P_Dot = i + 1;
    }
    int cnt = 0;
    if (str[0] == '0')
    {
        for (i = 0; i < len; i++)
        {
            if (str[i] != '0' && str[i] != '.')
            {
                cnt = i - 1;
                break;
            }
        }
        if (str[cnt + 2] != '\0')
        {
            printf("%c.", str[cnt + 1]);
            for (i = cnt + 2; i < len; i++)
                printf("%c", str[i]);
            printf("e-%d", cnt);
        }
        else
        {
            printf("%c", str[cnt + 1]);
            printf("e-%d", cnt);
        }
    }
    else if (P_Dot == 2)
    {
        strcat(str, "e0");
        puts(str);
    }
    else if(P_Dot > 2)
    {
        cnt=P_Dot-2;
        printf("%c.",str[0]);
        for(i=1;i<len;i++)
        {
            if(str[i]=='.')
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",cnt);
    }
    else if(P_Dot==0)//即整数情况
    {
        cnt=len-1;
        printf("%c.",str[0]);
        for(i=1;i<len;i++)
        {
            printf("%c",str[i]);
        }
        printf("e%d",cnt);
    }
    return 0;
}
