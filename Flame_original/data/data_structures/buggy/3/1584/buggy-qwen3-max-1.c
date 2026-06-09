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
                    printf(".");
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
    printf("e%d",c-b); @@ [The exponent calculation is incorrect. The logic for counting leading zeros before the first non-zero digit and adjusting the exponent accordingly is flawed. Additionally, the program fails to handle cases where the number starts with '0.' correctly, and it prints extra digits without properly normalizing to one non-zero digit before the decimal point as required by scientific notation. Also, trailing newline or EOF handling may cause misbehavior.]
    return 0;
}