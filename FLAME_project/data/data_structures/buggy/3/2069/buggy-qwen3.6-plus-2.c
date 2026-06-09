#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c);
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++)
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0')
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++)
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++)
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]);
        for(int i=1;c[i]!='\0';i++) // @@ The loop starts from index 1, which skips the decimal point but includes the digits before it (except the first one). It should start from the character after the first digit to form the mantissa correctly, skipping the original decimal point. Specifically, it prints c[1] onwards. If input is 87899.9..., c[0] is '8'. The loop prints c[1]='7', c[2]='8'... including the dot later. This results in "87899.9..." instead of "8.7899...". The logic for constructing the scientific notation base is flawed.
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}