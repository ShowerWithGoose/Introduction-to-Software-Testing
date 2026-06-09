#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
int main()
{
    int num1,num2,num3;
    char a,b,c;
    num1=0;a='+';
    while(a!='=')
    {
        scanf("%d %c",&num2,&b);    
        while(b=='*'||b=='/')
        {
            scanf("%d %c",&num3,&c);
            if(b=='*')
            num2=num2*num3;
            else if(b=='/')
            num2=num2/num3;
            b=c;
        }
        if(a=='+')
            num1=num1+num2;
        else if(a=='-')
            num1=num1-num2;
        a=b;
    }
 
    printf("%d",num1);
 
 return 0;
}



