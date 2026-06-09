#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in some environments, 'gets' is not available leading to compilation error]
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [Loop condition may access beyond string length if input has no non-zero digit after decimal; also, variable 'i' declared inside for-loop may not be supported in older C standards (pre-C99), causing compilation error in strict ANSI C mode]
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0') // @@ [Potential out-of-bounds access if 'n+1' exceeds string length; also logic flaw: assumes at least one digit after zeros, but doesn't validate]
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++) // @@ [Same issue: 'i' declared in for-loop may cause compilation error in pre-C99 compilers]
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++) // @@ [Again, 'i' declared in for-loop may not compile in older C standards; also, if input has no '.', loop runs indefinitely or accesses invalid memory]
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ [Incorrect output format: should print first digit followed by '.' and rest, but this prints only the last digit before decimal without proper normalization]
        for(int i=1;c[i]!='\0';i++) // @@ ['i' declaration in loop may cause compilation error; also logic error: starts from index 1, skipping first char but including decimal point and all following chars, producing malformed mantissa]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}