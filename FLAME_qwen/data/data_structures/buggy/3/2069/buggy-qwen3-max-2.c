#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed, leading to compilation error if compiler adheres strictly to standard]
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [Loop condition may access beyond string length if input lacks a non-zero digit after decimal point; also, variable-length loop without bounds check on array 'c']
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
        for(int i=0;c[i]!='.';i++) // @@ [If input has no decimal point, this loop runs indefinitely or accesses out-of-bounds memory, causing undefined behavior or crash]
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]);
        for(int i=1;c[i]!='\0';i++) // @@ [This prints from index 1 onward including the decimal point and fractional part, but should skip the decimal point and only print digits after it; also duplicates first digit incorrectly]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}