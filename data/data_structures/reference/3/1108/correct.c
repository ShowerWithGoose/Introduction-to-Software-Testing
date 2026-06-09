#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int i;
    char s[105];
    int a[105];
    int dian=0,k,t=0,weishu=0,flag=0;
    int fuhao=0;
    scanf("%s",s);
    k=strlen(s);
    if(s[0]=='-') fuhao=-1;
    for(i=0;i<k;i++)
    {
        if(s[i]=='.') dian=1;
        if(dian==1)   weishu++;
        if(s[i] != '0' && s[i] != '-' && s[i] != '.')
            flag=1;
        if(flag==1 && s[i] != '.')
            a[t++]=s[i]-'0';
    }
    weishu--;
    if(fuhao==-1)
        printf("-");
    for(i=0;i<t;i++)
    {
       if(i==1)
            printf(".%d",a[i]);
       else
        printf("%d",a[i]);
    }
    printf("e%d",t-1-weishu);
    return 0;
}

