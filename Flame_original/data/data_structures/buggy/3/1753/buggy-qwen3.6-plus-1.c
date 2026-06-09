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
        putchar(' '); // @@ Prints an unnecessary trailing space, which violates the output format.
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
    putchar(' '); // @@ Prints an unnecessary trailing space after the exponent, violating the output format.
}
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ 'gets' is unsafe and removed in C11, likely causing a compilation error. Use 'fgets' instead.
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
            putchar('.'); // @@ Unconditionally prints a decimal point. If the base is an integer (only one significant digit), no decimal point should be printed.
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
    x=y-w; // @@ Incorrectly calculates the exponent when the input is an integer (no '.'), as 'y' remains 0. The exponent should be 'strlen(s) - 1 - w' for integers.
    if(y>w)
    {
        x-=1;
    }
    if(y<w)
    {
        x-=0; // @@ Redundant operation that does nothing and does not affect the logic.
    }
    wrt(x);
}