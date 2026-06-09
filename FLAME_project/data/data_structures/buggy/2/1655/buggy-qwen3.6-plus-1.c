#include <stdio.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a = 0;
    x = '+';
    while(x!='=')
    {
        scanf("%d %c",&b,&y);   // @@ The original code passed 'y' instead of '&y' to scanf, causing undefined behavior and likely a crash (Runtime Error) because scanf requires the address of the variable to store the input.
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