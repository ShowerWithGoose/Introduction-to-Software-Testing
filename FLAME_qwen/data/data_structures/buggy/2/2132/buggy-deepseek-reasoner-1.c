#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f;
    char m,n,p,q;
    scanf(" %d %c",&a,&m);
    
    A:while(m=='/'||m=='*'){
        scanf("%d %c",&b,&n);
        if(m=='/')a/=b;
        else a*=b;
        m==n; // @@ 这里应该是赋值 m=n; 而不是比较。写成比较导致 m 无法更新，如果读到的是加减或等号，循环不会退出，程序会继续等待输入或陷入死循环。
    }
    while(m=='+'||m=='-'){
        scanf("%d %c",&b,&n);
        if(n=='+'||n=='-'||n=='='){
            if(m=='+')a+=b;
            else a-=b;
            m=n;
        }
        else break;
        
    }
    while(n=='/'||n=='*'){
            scanf("%d %c",&c,&p);
            if(n=='/')b/=c;
            else b*=c;
            n=p;
    }
    if(m=='+'){a+=b;m=n;}
    else if(m=='-'){a-=b;m=n;}
    
    
    if(m=='=')printf("%d",a);
    else goto A;
    return 0;
}