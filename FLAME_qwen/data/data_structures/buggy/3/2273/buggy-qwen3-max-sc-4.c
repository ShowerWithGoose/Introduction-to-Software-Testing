#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++; // @@ [The index 'i' is only incremented when the character is not '.', causing '.' to be overwritten in the next iteration and leading to incorrect storage of input. Also, the loop condition reads one extra character beyond newline due to EOF check instead of checking for '\n'.]
    }
    i--; // @@ [This decrements 'i' assuming the last read was a newline or EOF, but due to flawed input reading logic, 'i' may not correctly point to the end of the valid input string.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ [The exponent should be 'l-1' (number of zeros after decimal before first non-zero), not 'l'. For example, "0.001" should give e-3, not e-2.]
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ [Same exponent error: should be 'k-1', not 'k'.]
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]); // @@ [This prints all characters including those after the decimal point, but skips the last character because loop condition is 'l<i' where 'i' was decremented earlier—may miss last digit. Also, it doesn't skip the '.' character properly since '.' was stored at position 't' but not excluded in this loop.]
        printf("e%d",t-1);
    }
    return 0;
}