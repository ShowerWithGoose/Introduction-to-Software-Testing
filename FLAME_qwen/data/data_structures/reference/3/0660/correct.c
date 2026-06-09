//
//  main.c
//  notation
//
//  Created by  on 2022/3/6.
//
/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
int main ()
{
    char str[MAXN];
    int i, power;
    scanf("%s", str);
    if (str[0]=='0')
    {
        for (i=2; str[i]!='\0'; i++)
        {
            if (str[i]!='0')
            {
                power=1-i;
                if (str[i+1]!='\0')
                    printf("%d.", str[i]-'0');
                else
                    printf("%d", str[i]-'0');
                break;
            }
        }
        i++;
        for(;str[i]!='\0'; i++)
        {
            printf("%d", str[i]-'0');
        }
    }
    else
    {
        printf("%d.", str[0]-'0');
        for (i=1; str[i]!='\0'; i++)
        {
            if (str[i]=='.')
            {
                power=i-1;
            }
            else
            {
                printf("%d", str[i]-'0');
            }
        }
    }
    printf("e%d\n", power);
    
    
    
    
    return 0;
}

