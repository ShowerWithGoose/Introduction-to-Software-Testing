#include<stdio.h>
#include<string.h>
char a[150];
int main()
{
    gets(a);
    int i,j,k;
    if(a[0]=='0')
    {
        for(i=2;a[i]!='\0';i++)
        {
            if(a[i]!='0')
                break;
        }
        if(a[i+1]!='\0')
        {
            printf("%c%c",a[i],'.');
            for(j=i+1;a[j]!='\0';j++)
                printf("%c",a[j]);
            printf("%c%c%d",'e','-',i-1);
        }
        else
        {
            printf("%c%c%c%d",a[i],'e','-',i-1);
        }
    }
    else if(a[0]!='0'&&a[1]=='.')
    {
        for(i=0;a[i]!='\0';i++)
        {
            printf("%c",a[i]);
        }
        printf("%c%c",'e','0');
    }
    else
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='.')
                break;
        }
        printf("%c%c",a[0],'.');
        for(k=1;a[k]!='\0';k++)
        {
            if(a[k]!='.')
                printf("%c",a[k]);
        }
        printf("%c%d",'e',i-1);
    }
    return 0;
}

