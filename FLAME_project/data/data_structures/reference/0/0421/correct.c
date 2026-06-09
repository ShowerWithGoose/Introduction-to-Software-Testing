#include<stdio.h>
#include<string.h>
#include <ctype.h>
int main()
{
    char a[100],b;
    int i=0;
    gets(a);
    for(i=0;a[i]; i++)
    {
        if(a[i]=='-')
        {
            if(isdigit(a[i-1])&&isdigit(a[i+1])&&a[i-1]<=a[i+1])
            {
                for(b=a[i-1]+1;b<a[i+1];b++)
                        printf("%c",b);
            }
        else if(islower(a[i-1])&&islower(a[i+1])&&a[i-1]<=a[i+1])
            {
               for(b=a[i-1]+1;b<a[i+1];b++)
                        printf("%c",b);
            }
        else if(isupper(a[i-1])&&isupper(a[i+1])&&a[i-1]<=a[i+1])
            {
               for(b=a[i-1]+1;b<a[i+1];b++)
                        printf("%c",b);
            }
        else
            printf("%c",a[i]);
        }
        else
            printf("%c",a[i]);
    }
    return 0;
}

