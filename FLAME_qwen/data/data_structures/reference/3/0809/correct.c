#include<stdio.h>
#include<string.h>
char num[105];
int main()
{
    gets(num);
    int dot=0,len=strlen(num);
    int i,a;
    for(i=0;i<len;i++)
    {
        if(num[i]=='.')
        {
            dot=i;
        }
    }
    if(dot==0)
    {
        puts(num);
        return 0;
    }
    else if(dot==1)
    {
        if(num[0]=='0')
        {
            for(i=2;i<len;i++)
            {
                if(num[i]!='0')
                {
                    a=i;
                    break;
                }
            }
            if(a==len-1)
            {
                printf("%c",num[a]);
                printf("e-%d",a-1);
                return 0;
            }
            else
            {
                printf("%c.",num[a]);
                for(i=a+1;i<len;i++)
                {
                    printf("%c",num[i]);
                }
                printf("e-%d",a-1);
                return 0;
            }
        }
        else
        {
            for(i=0;i<len;i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
            return 0;
        }
    }
    else
    {
        printf("%c.",num[0]);
        for(i=1;i<len;i++)
        {
            if (num[i]!='.')
            {
                printf("%c",num[i]);
            }
        }
        printf("e%d",dot-1);
        return 0;
    }
    return 0;
}

