#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern compilers, 'gets' is removed entirely causing compilation error]
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [Loop condition may access beyond string length if input has no non-zero digit after decimal; also, variable 'i' declared inside for-loop requires C99 mode which may not be enabled by default]
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0')
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++) // @@ [Variable 'i' declared inside for-loop requires C99 mode which may not be enabled by default]
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++) // @@ [Variable 'i' declared inside for-loop requires C99 mode which may not be enabled by default; also, if input has no '.', this loop runs past end of string causing undefined behavior]
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]);
        for(int i=1;c[i]!='\0';i++) // @@ [Variable 'i' declared inside for-loop requires C99 mode which may not be enabled by default]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}