#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[105];
    int i,end,point,begin;
    gets(a);
    for(i=strlen(a)-1; i>=0; i--)
    {
        if(a[i]=='.')
        {
            point=i;
        }
    }
    for(i=strlen(a)-1; i>=0; i--)
    {
        if(a[i]!='0'&&a[i]!='.')
        {
            end=i;
            break;
        }
    }
    if(a[0]>='1')
    {
        if(end==0)
        {
            printf("%ce%d",a[0],point-1);
        }
        else
        {
            printf("%c.",a[0]);
            for(i=1;i<=end;i++)
            {
                if(a[i]!='.')
                {
                    printf("%c",a[i]);
                }
            }
            printf("e%d",point-1);
        }
    }
    else
    {
        for(i=0;i<=strlen(a)-1;i++)
        {
            if(a[i]!='0'&&a[i]!='.')
            {
                begin=i;
                break;
            }
        }
        if(begin==end)
        {
            printf("%ce-%d",a[end],begin-1);
        }
        else
        {
            printf("%c.",a[begin]);
            for(i=begin+1;i<=end;i++)
            {
                printf("%c",a[i]);
            }
            printf("e-%d",begin-1);
        }
    }
    return 0;
}

