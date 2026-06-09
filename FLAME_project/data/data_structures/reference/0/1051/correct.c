#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char a[1000];
char b;
int main()
{
    gets(a);
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if(a[i-1]<a[i+1]&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')))
            {
                for(b=a[i-1]+1;b<a[i+1];b++)
                    printf("%c",b);
            }
            else printf("%c",a[i]);
        }
        else printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}

