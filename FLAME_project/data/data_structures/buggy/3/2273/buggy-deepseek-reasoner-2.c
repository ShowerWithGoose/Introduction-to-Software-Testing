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
        i++;
    }
    i--; // @@ This decrement assumes there is a trailing newline, causing off-by-one error when newline is absent, leading to the condition on line 18 being false and the else branch executing.
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l);
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ This always prints a decimal point even when the number has only one significant digit (like in "0.9"), which should not have a decimal point.
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}