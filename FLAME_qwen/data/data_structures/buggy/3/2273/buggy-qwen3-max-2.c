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
        i++; // @@ [The index 'i' is only incremented when the character is not '.', causing '.' to be overwritten in the next iteration and leading to incorrect storage of input. Also, newline or other whitespace may be included in the array, corrupting parsing.]
    }
    i--; // @@ [This decrements 'i' assuming the last character read was a newline or EOF marker, but due to flawed input reading logic above, 'i' may not correctly point to the end of the significant input.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ [The exponent should be l-1 (number of zeros after decimal before first non-zero), not l. For example, "0.001" should give e-3, but this prints e-2.]
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ [Same exponent error: should be k-1, not k.]
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]); // @@ [This loop prints all characters from index 1 to i-1, including the '.' if it was stored, because the input reading logic does not skip or remove the decimal point. This leads to output like "1.2.3e1" for input "12.3".]
        printf("e%d",t-1);
    }
    return 0;
}