#include<stdio.h>
#include<string.h>
char a[10000001];
char fuhao;
int f,sum,tsum,num,la,t;
int main()
{
    f=1;
    scanf("%d ",&tsum);
    while(scanf("%c",&fuhao))
    {
        if(fuhao=='=')
            break;
        scanf(" %d ",&num);
        if(fuhao=='-')
        {
            sum+=tsum*f;
            tsum=num;
            f=-1;
        }
        if(fuhao=='+')
        {
            sum+=tsum*f;
            tsum=num;
            f=1;
        }
        if(fuhao=='*')
            tsum*=num;
        if(fuhao=='/')
            tsum/=num;
    }
    sum+=tsum*f;
    printf("%d",sum);
}
