#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int i=0,flag=0;
    if(strchr(s,'.')==NULL)
    {
        for(i=len-1;i>=1;i--)
        {
            if(s[i]!='0')
            {
                flag=i;
                break;
            }
        }
        if(flag==0)
        {
            printf("%c",s[0]);
        }
        else
        {
            printf("%c.",s[0]);
            for(i=1;i<=flag;i++)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",len-1);
    }
    else
    {
        if(s[0]=='0')
        {
            for(i=0;i<len;i++)
            {
                if(s[i]!='0'&&s[i]!='.')
                {
                    flag++;
                }
                if(flag==2)
                {
                    printf(".");
                }
                if(flag!=0)
                {
                    printf("%c",s[i]);
                }
            }
            printf("e%d",2-len); // @@ 错误：指数计算错误，应为第一个非零数字之后的位置偏移，而不是2-len。对于输入"0.00000009123456789012"，len=22，2-len=-20，但正确指数应为-8。
        }
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='.')
                {
                    flag=i;
                    break;
                }
            }
            printf("%c",s[0]);
            printf(".");
            for(i=1;i<len;i++)
            {
                if(s[i]!='.')
                printf("%c",s[i]);
            }
            printf("e%d",flag-1);
        }
    }
    return 0;
}