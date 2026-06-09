#include <stdio.h>
#include <string.h>
int main()
{
    int len,i,point,first;
    char a[101];
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(a[i]==46)
        {
            point=i;
        }
    }
    for(i=0;i<len;i++)
    {
        if(a[i]>48)
        {
            first=i;
            break;
        }
    }
    
    if(first>point&&first==len-1)
    {
        printf("%c",a[first]);
        printf("e-%d",first-point);
        return 0;
    }
    if(first>point)
    {
        printf("%c.",a[first]);
        for(i=first+1;i<len;i++)
        {
            printf("%c",a[i]);
        }
        printf("e-%d",first-point);
    }
    if(first<point)
    {
        printf("%c.",a[first]);
        for(i=first+1;i<len;i++)
        {
            if(a[i]!=46)
            {
                printf("%c",a[i]);
            }
        }
        printf("e%d",point-first-1);
    }
}
