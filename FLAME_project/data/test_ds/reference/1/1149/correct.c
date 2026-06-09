#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,b;
    char c;
    char a[100];
    gets(a);
    b=strlen(a);
    for(i=0;i<b;i++)
    {
        if(a[i]!='-')
        {
            printf("%c",a[i]);
        }
        else
        {
            if(a[i-1]<='z' && a[i-1]>='a' && a[i+1]<='z' && a[i+1]>='a' && a[i+1]>a[i-1])
            {
                for(j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    printf("%c",a[i-1]+j);
                }
            }
            if(a[i-1]<='Z' && a[i-1]>='A' && a[i+1]<='Z' && a[i+1]>='A' && a[i+1]>a[i-1])
            {
                for(j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    printf("%c",a[i-1]+j);
                }
            }
            if(a[i-1]<='9' && a[i-1]>='0' && a[i+1]<='9' && a[i+1]>='0' && a[i+1]>a[i-1])
            {
                for(j=1;j<(a[i+1]-a[i-1]);j++)
                {
                    printf("%c",a[i-1]+j);
                }
            }
            if(a[i+1]<=a[i-1])
            {
                printf("-");
            }
            if(a[i+1]<='Z' && a[i+1]>='A' && a[i-1]<'A')
            {
                printf("-");
            }
            if(a[i+1]<='z' && a[i+1]>='a' && a[i-1]<'A')
            {
                printf("-");
            }
            if(a[i+1]<='z' && a[i+1]>='a' && a[i-1]<'a')
            {
                printf("-");
            }
        }
    }
}
