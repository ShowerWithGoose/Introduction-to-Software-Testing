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
        m==n; // @@ [Logical error: This is a comparison expression that evaluates to true/false but does not assign the value of n to m. It should be m=n;. Because m is never updated, if the initial operator is * or /, this loop becomes infinite, causing Time Limit Exceeded.]
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