#include<stdio.h>
int main()
{
    char a;
    int b=0,c=-1,d=1,biao1=0,biao2=0;
    while(scanf("%c",&a)!=EOF) // @@ This loop does not stop at the newline character, causing the program to wait for EOF instead of processing a single line of input. The problem specifies that the input ends with a newline, so the program should read until newline or use a line-based input function.
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
                    printf("."); // @@ This always prints a decimal point after the first non‑zero digit, even if there are no subsequent digits. For numbers like 0.1, the output becomes "1.e-1" instead of "1e-1". The decimal point should only be printed if additional digits follow.
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