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
                    printf("."); // @@ The code unconditionally prints a decimal point after the first significant digit. However, if there are no subsequent significant digits (e.g., input "0.9" results in base "9"), the output should be an integer without a decimal point (expected "9e-1", got "9.e-1"). The decimal point should only be printed if there are more digits to follow in the mantissa.
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
    printf("e%d",c-b);
    return 0;
}