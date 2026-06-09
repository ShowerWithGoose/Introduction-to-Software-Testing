#include <stdio.h>

int main()
{
    int sum,a2,a3;
    char b1,b2,b3;
    sum=0;
    b1='+';
    while (1)
    {
        scanf("%d %c",&a2,&b2);
 
        while(b2=='*'||b2=='/')
        {
            scanf("%d %c",&a3,&b3);
            if(b2=='*')a2=a2*a3;else a2=a2/a3;
            b2=b3;
        }
 
 
        if(b1=='+')sum+=a2;
        else if(b1=='-')sum-=a2;
 
        b1=b2;
 
        if(b1=='='){printf("%d\n",sum);break;}
    }
 
    return 0 ;
}
 

