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
        putchar(' ');
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
    putchar(' ');
}
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. Moreover, the problem states input ends with a newline, but `gets()` removes the newline, which may affect position calculations. Also, in modern C standards, `gets()` is removed entirely, leading to compilation errors on compliant compilers.]
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
            putchar('.');
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
        x-=0;
    }
    wrt(x); // @@ [The `wrt` function always appends a space after the number, but the expected output format does not include any trailing space. This causes incorrect output formatting. Additionally, the exponent logic is flawed: for numbers like "123.45", the exponent should be 2, but this code computes y - w (position of '.' minus position of first non-zero digit), then subtracts 1 only if y > w, which doesn't correctly handle all cases (e.g., numbers less than 1 like "0.00123").]
}