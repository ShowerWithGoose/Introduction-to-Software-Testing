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
        printf("%c",c[n-1]); // @@ This incorrectly prints the last digit before the decimal point instead of the first significant digit. It should print c[0] followed by a decimal point.
        for(int i=1;c[i]!='\0';i++) // @@ This loop prints all characters from index 1, including the decimal point, causing duplicated digits and incorrect formatting. It should skip the decimal point and print the remaining significant digits.
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}