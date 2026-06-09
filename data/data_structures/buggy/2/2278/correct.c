#include<stdio.h>
int main()
{
    int ans=0;
    int a,b,c,d;
    char o,p,q;//q第一个数前的符号，后面是前一组的符号
    q='+';
    while(q!='=')
    {
        scanf("%d %c ",&a,&o);//每次读一个数和一个符号
        while((o=='*')||(o=='/'))//先乘除
        {
            scanf("%d %c ",&b,&p);
            if(o=='*')
            {
                a=a*b;
                o=p;
            }
            else if(o=='/')
            {
                a=a/b;
                o=p;
            }
        }
        if(q=='+')//再加减
        {
            ans=ans+a;
        }
        else if(q=='-')
        {
            ans=ans-a;
        }
        q=o;   
    }
    printf("%d",ans);
    return 0;
}
