#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [Loop condition may access beyond string length if input has no non-zero digit after leading zeros and decimal point, causing undefined behavior; also, variable-length loop without bounds check]
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0') // @@ [If n points to last character, c[n+1] reads past end of string, leading to undefined behavior]
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
        for(int i=0;c[i]!='.';i++) // @@ [If input has no decimal point, loop runs past end of string, causing undefined behavior]
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ [This prints only the last digit before '.', but should print first digit followed by others after decimal; logic is incorrect for scientific notation format]
        for(int i=1;c[i]!='\0';i++) // @@ [Starts printing from index 1, skipping first digit already printed, but includes the decimal point and rest; this produces malformed base part like "123.45" -> "123.45e2" instead of "1.2345e2"]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}