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
                    printf("."); // @@ The decimal point is printed immediately after the first non-zero digit, even if there are no more digits after it. This causes an extra decimal point for numbers like "0.9" where the only significant digit is the last one. The dot should only be printed if there is at least one more digit to follow.
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