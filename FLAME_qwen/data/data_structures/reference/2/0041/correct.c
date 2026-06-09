# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main()
{
    int num1,num2,num3;
    char a,b,c;
    num1=0;
    a='+';
    
    scanf("%d %c",&num2,&b);
    
    while (1)
    {
        
        if(b=='*'||b=='/')
        {
            
            scanf("%d %c",&num3,&c);
            
            if(b=='*') 
			{
			num2=num2*num3;}
            else if(b=='/') 
			{
			num2=num2/num3;}
            
            b=c;
            
        }
        
        if(b=='+'||b=='-')
        {
            if(a=='+') num1=num1+num2;
            else if(a=='-') num1=num1-num2;
            
            
            a=b;
            scanf("%d %c",&num2,&b);
            
        }
        
        if(b=='=')
        {
            if(a=='+') num1=num1+num2;
            else if(a=='-') num1=num1-num2;
            
            printf("%d\n",num1);
            break;
            
        }
    }
    
    return 0 ;
}


