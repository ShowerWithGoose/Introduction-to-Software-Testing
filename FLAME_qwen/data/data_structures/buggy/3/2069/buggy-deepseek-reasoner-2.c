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
        for(int i=0;c[i]!='.';i++) // @@ This loop sets n to the index of the last digit before the decimal, but then n is incremented incorrectly, causing the base to be constructed from the wrong digit.
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ This prints the last digit of the integer part, but should print the first digit before the decimal point.
        for(int i=1;c[i]!='\0';i++) // @@ This prints characters from index 1 onward (skipping the first digit), including the decimal point and the rest, which results in a malformed base.
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}