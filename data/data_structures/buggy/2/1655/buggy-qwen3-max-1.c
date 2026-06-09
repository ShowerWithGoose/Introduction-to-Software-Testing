#include <stdio.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a = 0;
    x = '+';
    while(x!='=')
    {
        scanf("%d %c",&b,y);   // @@ [Passing 'y' (char) instead of '&y' (address of char) to scanf leads to undefined behavior; should be &y]
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