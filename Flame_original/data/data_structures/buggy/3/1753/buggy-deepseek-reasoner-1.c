#include<stdio.h>
int r()
{
    int x_=0,y_=1;
    char z_=getchar();
    while(z_<'0'||z_>'9')
    {
        if(z_=='-')
        {
            y_=-1;
        }
        z_=getchar();
    }
    while(z_>='0'&&z_<='9')
    {
        x_=x_*10+z_-'0';
        z_=getchar();
    }
    return x_*y_;
}
void wrt(int _x)
{
    if(_x==0)
    {
        putchar('0');
        putchar(' '); // @@ Prints a space after the exponent when exponent is 0, which is not part of the required output format.
        return;
    }
    char _X[600];
    int tp=0;
    if(_x>0&&0<_x)
    {
        tp=_x;
    }
    else
    {
        tp=-_x;
    }
    if(_x<0&&0>_x)
    {
        putchar('-');
    }
    int tot=0;
    for(;tp!=0;)
    {
        _X[tot]=tp%10+'0';
        tp/=10;
        tot++;
    }
    for(;tot!=0;)
    {
        tot--;
        putchar(_X[tot]);
    }
    putchar(' '); // @@ Prints a trailing space after the exponent, which is not allowed in the output format.
}
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ Using gets() is unsafe and deprecated; it can cause buffer overflow and is not standard in modern C (C11 and later). It may also lead to compilation warnings/errors in strict environments.
    int z=0;
    int y=0;
    int w=0;
    int x=0;
    for(int q=0;q!=(strlen(s));q++)
    {
        if(s[q]!='0'&&s[q]!='.'&&z==0)
        {
            z=1;
            putchar(s[q]);
            putchar('.'); // @@ This unconditionally prints a decimal point after the first significant digit, even when there are no more digits (e.g., input "0.1" produces "1."). The decimal point should only be printed if there is at least one more significant digit.
            w=q;
            continue;
        }
        if(s[q]=='.')
        {
            y=q;
            continue;
        }
        if(z==0)
        {
            continue;
        }
        putchar(s[q]);
    }
    putchar('e');
    x=y-w;
    if(y>w)
    {
        x-=1;
    }
    if(y<w)
    {
        x-=0; // @@ This line is redundant (subtracting 0 does nothing), but not a logical error by itself.
    }
    wrt(x);
}