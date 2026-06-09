#include<stdio.h>
int main()
{
    char a;
    int b=0,c=-1,d=1,biao1=0,biao2=0;
    while(scanf("%c",&a)!=EOF)
    {
        if(a=='.')
        {
            biao2=1;
        }
        else if(a>='0'&&a<='9')
        {
            if(a!='0')
            {
                biao1=1;
            }
            if(biao1==1)
            {
                printf("%c",a);
                if(d==1)
                {
                    printf("."); // @@ [This always prints a decimal point after the first significant digit, even when there are no following digits, leading to trailing '.' like "9." instead of "9"]
                    d=0;
                }
                c++;
            }
            if(biao2==1)
            {
                b++;
            }
        }
    }
    printf("e%d",c-b); // @@ [The exponent calculation is incorrect because 'c' counts significant digits printed minus one, and 'b' counts digits after decimal before any non-zero, but logic doesn't align with scientific notation rules for cases like "0.9"]
    return 0;
}