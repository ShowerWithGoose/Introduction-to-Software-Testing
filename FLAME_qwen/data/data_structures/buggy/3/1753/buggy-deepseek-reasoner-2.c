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
        putchar(' '); // @@ Trailing space not required by output format
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
    putchar(' '); // @@ Trailing space not required by output format
}
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ Using gets is unsafe and may cause compilation error in modern C standards (C11 removed gets)
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
            putchar('.'); // @@ Always adds a decimal point after the first significant digit, even if no digits follow (e.g., input "0.5" produces "5.")
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
    x=y-w; // @@ Exponent calculation incorrect for numbers without a decimal point (y remains 0, giving wrong exponent)
    if(y>w)
    {
        x-=1;
    }
    if(y<w)
    {
        x-=0; // @@ This line does nothing; the logic is incomplete (e.g., for integers, y==w and exponent wrong)
    }
    wrt(x);
}