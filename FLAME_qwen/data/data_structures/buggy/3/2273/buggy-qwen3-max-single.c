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
        i++; // @@ [The index 'i' is incremented only when the character is not '.', causing '.' to be overwritten in the next iteration and leading to incorrect storage of input. Also, the loop condition reads one extra character beyond newline due to EOF check instead of stopping at '\n'.]
    }
    i--; // @@ [This decrements 'i' assuming the last read was a newline or EOF, but due to flawed input reading logic, 'i' may not correctly point to the end of the valid input string.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l);
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]); // @@ [This loop prints all characters including digits after the decimal point, but it does not skip the '.' character which was stored in the array, leading to incorrect output if '.' is present in the printed part.]
        printf("e%d",t-1);
    }
    return 0;
}