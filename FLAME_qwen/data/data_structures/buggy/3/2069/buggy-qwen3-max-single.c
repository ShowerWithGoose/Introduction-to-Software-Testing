#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [Loop condition may access beyond string length if input lacks decimal point or has no non-zero digits after zeros]
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0') // @@ [Potential out-of-bounds access if 'n+1' exceeds string length]
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
        for(int i=0;c[i]!='.';i++) // @@ [If input has no decimal point, loop runs indefinitely or accesses out-of-bounds memory]
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ [Only prints first digit but should print all digits before decimal followed by those after without decimal point in base part]
        for(int i=1;c[i]!='\0';i++) // @@ [Starts printing from index 1, skipping first digit again and including the decimal point which should be omitted]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}