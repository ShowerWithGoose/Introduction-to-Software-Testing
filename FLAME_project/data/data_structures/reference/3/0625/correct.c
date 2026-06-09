#include<stdio.h>
#include<string.h>

int main()
{
    char a[105];
    gets(a);
    if(a[0]=='0')
    {
        int e=0;
        int i=2;
        for(;a[i]=='0';i++)
        {
            e--;
        }
        e--;
        printf("%c",a[i]);
        i++;
        if(a[i]!='\0')
        {
            printf(".");
        }
        for(;a[i]!='\0';i++)
        {
            printf("%c",a[i]);
        }
        printf("e");
        printf("%d",e);
    }
    else if(a[1]=='.'&&a[0]!='0')
    {
        printf("%se0",a);
    }
    else 
    {
        int i=0;
        for(;a[i]!='.';i++);
        printf("%c.",a[0]);
        int j=1;
        for(;j<i;j++)
        {
            printf("%c",a[j]);
        }
        j++;
        for(;a[j]!='\0';j++)
        {
            printf("%c",a[j]);
        }
        printf("e%d",i-1);
    }
    return 0;
}
