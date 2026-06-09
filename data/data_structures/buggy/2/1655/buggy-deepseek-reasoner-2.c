#include <stdio.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a = 0;
    x = '+';
    while(x!='=')
    {
        scanf("%d %c",&b,y);   // @@ Missing '&' before y; should be &y to pass address of y
        while(y=='*' || y=='/')
        {
            scanf("%d %c",&c,&z);
            if(y=='*')
               b *= c;
            else if(y=='/')
                b /= c;
            y= z;    
        }
        if(x=='+')
            a+= b;
        else if(x=='-')
            a -= b;
        x = y;   
    }
    printf("%d",a);
    return 0;
}