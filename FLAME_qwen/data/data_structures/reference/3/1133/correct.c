#include <stdio.h>
#include <string.h>
int main()
{
    char a[110];
    char b[110];
    int i=0,j=0,m=0,flag=0;
    scanf("%s",a);
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]!='0'&&a[i]!='.') flag=1;
        if(flag==1&&a[i]!='.') b[j++]=a[i]-'0';
    }
    if(a[0]=='0')
    {
        for(i=1;i<=strlen(a);i++)
            if(a[i]!='0'&&a[i]!='.')break;m=i-1;
        if(j==2)printf("%d",b[0]);
        else if(j==3)printf("%d.%d",b[0],b[1]);
            else
        {printf("%d",b[0]);
        printf(".%d",b[1]);
            for(i=2;i<j-1;i++) printf("%d",b[i]);}
        printf("e-%d",m);
    }
    if(a[0]!='0')
    {
        for(i=1;i<=strlen(a);i++)
            if(a[i]=='.')break;m=i-1;
        if(j==2)printf("%d",b[0]);
        else if(j==3)printf("%d.%d",b[0],b[1]);
            else
        {printf("%d",b[0]);
        printf(".%d",b[1]);
            for(i=2;i<j-1;i++) printf("%d",b[i]);}
        printf("e%d",m);
    }
    return 0;
}



