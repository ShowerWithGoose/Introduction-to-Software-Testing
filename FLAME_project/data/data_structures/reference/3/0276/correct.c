#include<stdio.h>
#include<string.h>
char a[100],b[100],c[100];
int i;
int main()
{
    scanf("%[0-9].%[0-9]",a,b);
    for(int i=strlen(b)-1;b[i]=='0';i--)
        b[i]=0;
    if(a[0]=='0')
    {
        for(;b[i]=='0';i++)
            ;
        printf("%c%s%se-%d",b[i],i==strlen(b)-1?"":".",b+i+1,i+1);
    }
    else 
        printf("%c%s%s%se%d",a[0],a[1]==0&&b[0]==0?"":".",a+1,b,strlen(a)-1);
    return 0;
}



