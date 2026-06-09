# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main()
{
    int a=0,b,c,g=1;
    char d='+',e,f;
    scanf("%d %c",&b,&e);
    while (g!=0)
    {
        if(e=='*'||e=='/')
        {
            scanf("%d %c",&c,&f);
            if(e=='*') b=b*c;
            else if(e=='/') b=b/c;
            e=f;
        }
        if(e=='+'||e=='-')
        {
            if(d=='+') a=a+b;
            else if(d=='-') a=a-b;
            
            
            d=e;
            scanf("%d %c",&b,&e);   
        }
        if(e=='=')
        {
            if(d=='+') a=a+b;
            else if(d=='-') a=a-b;
            printf("%d\n",a);
            break;   
        }
    }
    
    return 0 ;
}

