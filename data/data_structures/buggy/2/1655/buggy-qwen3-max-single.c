#include <stdio.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a = 0;
    x = '+';
    while(x!='=')
    {
        scanf("%d %c",&b,y);   // @@ [Passing 'y' (a char) instead of '&y' (address of char) to scanf leads to undefined behavior; this is a runtime error, but in some environments may cause compilation warnings or errors depending on compiler settings]
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