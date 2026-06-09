#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define max 128
#define true 1
int main()
{
    int i,j=0,k;
    char a[1000],b[1000];
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')))
        {
            if(a[i-1]==b[j-1]&&a[i-1]!=a[i-2])
                k=1;
            else
                k=0;
            for(;a[i-1]+k<=a[i+1];k++)
            {
                b[j++]=a[i-1]+k;
            }
            i+=1;
        }
        else
        {
            b[j++]=a[i];
        }
    }
    b[j]='\0';
    printf("%s\n",b);
    return 0;
}
