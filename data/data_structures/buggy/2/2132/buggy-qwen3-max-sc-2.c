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
        m==n; // @@ [This line uses '==' (comparison) instead of '=' (assignment). It should assign n to m to continue parsing the next operator, but it does nothing due to the comparison.]
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