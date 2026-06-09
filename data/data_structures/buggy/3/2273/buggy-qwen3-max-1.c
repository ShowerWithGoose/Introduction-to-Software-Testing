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
        i++; // @@ [The loop reads one character at a time, but increments `i` only when the character is not '.', causing '.' to be overwritten in the next iteration. This leads to incorrect storage of the input string and loss of the decimal point position.]
    }
    i--; // @@ [This decrements `i` assuming the last read was a newline or EOF, but due to the flawed input reading logic above, `i` may not correctly represent the last valid index of the input string.]
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
        printf("%c",c[l]); // @@ [This loop skips the decimal point but also may miss characters or include garbage because the input string `c` was not correctly stored due to the earlier input reading bug. Additionally, it assumes all characters from index 1 to i-1 are digits, which may not hold if the decimal point was overwritten.]
        printf("e%d",t-1); // @@ [`t` stores the index of the decimal point, but due to the flawed input reading logic (overwriting '.'), `t` may be incorrect or uninitialized if '.' was never properly recorded.]
    }
    return 0;
}