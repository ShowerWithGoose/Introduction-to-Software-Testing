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
        putchar(' '); // @@ [Outputs an unnecessary trailing space, violating the output format.]
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
    putchar(' '); // @@ [Outputs an unnecessary trailing space after the exponent, violating the output format.]
}
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ [The `gets` function is deprecated and removed in C11, causing compilation errors in modern environments. Use `fgets` instead.]
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
            putchar('.'); // @@ [Unconditionally prints a decimal point. If the mantissa has only one significant digit, it should be printed as an integer without a decimal point.]
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
        x-=0; // @@ [Redundant operation that does not affect the result and can be removed.]
    }
    wrt(x);
} // @@ [Missing `return 0;` at the end of main, which may cause compilation warnings/errors in strict modes.]