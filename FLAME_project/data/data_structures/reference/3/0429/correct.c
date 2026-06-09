#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    int i,j,k,count1,h;
    gets(a);
    for(i = 0;i < strlen(a);i++)
    {
        if(a[i] == '.') break;
    }
    if(i == strlen(a)) //整数，没有小数点
    {
        printf("%c",a[0]);
        for(k=1,count1=0;k<=strlen(a)-1;k++)
        {
            if(a[k] == '0');
                count1++;
        }
        if(count1==strlen(a)-1) //科学计数法的底数为整数
        {
            printf("e%d",count1);
        }
        else
        {
            for(k=strlen(a)-1;a[k]=='0';k--)
            {
            }
            printf(".");
            for(h=1;h<=k;h++)
                printf("%c",a[h]);
            printf("e%d",strlen(a)-1);
        }
    }
    else        // 小数，有小数点
    {
        if(a[0] == '0')  //小数小于1时，有问题
        {
            for(j = 2;j <= strlen(a)-1;j++)
            {
                if(a[j]!='0')
                    break;
            }
            if(j == strlen(a) - 1)  //只有一位有效数字时
            {
                printf("%ce-%d",a[j],j-1);
            }
            else  //有多位有效数字时,有问题
            {
                printf("%c.",a[j]);
                for(k = j+1;k <= strlen(a)-1;k++)
                    printf("%c",a[k]);
                printf("e-%d",j-1);
            }
        }
        else  //小数大于1时
        {
            printf("%c.",a[0]);
            for(k = 1;k <= i-1;k++)
                printf("%c",a[k]);
            for(k = i+1;k <= strlen(a)-1;k++)
                printf("%c",a[k]);
            printf("e%d",i - 1);
        }

    }

    system("pause");
    return 0;
}


