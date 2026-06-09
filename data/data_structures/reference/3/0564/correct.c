#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[105];
    scanf("%s",a);
    int i,j,l,k=0,m;
    l=strlen(a);
    for(i=0;a[i]!='.';i++);
    if(i==1)
    {
        if(a[0]=='0')
        {
            i++;
            for(;a[i]=='0';i++) k++;
            printf("%c",a[i]);
            if(i<l-1) printf(".");
            for(i++;i<l;i++) printf("%c",a[i]);
            printf("e-%d\n",k+1);
        }
        else
        {
            printf("%se0\n",a);
        }
    }
    else
    {
        printf("%c",a[0]);
        for(m=l-1;a[m]=='0';m--);
        if(a[i-1]=='0') for(m=i-1;a[m]=='0';m--);
        if(m>1) printf(".");
        for(j=1;j<=m;j++) if(a[j]!='.') printf("%c",a[j]);
        printf("e%d\n",i-1);

    }
    return 0;

}

















