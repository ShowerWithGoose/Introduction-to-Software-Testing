#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ gets() is unsafe and may cause buffer overflow; also, it does not handle input ending with newline correctly in all cases. The problem expects input from console ending with newline, but gets() reads until newline and discards it, which is acceptable, but the main issue is that gets() is deprecated and can cause compilation errors on some systems.
    if(str[0]!='0')
    {
        while(str[i]!='.')
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++)
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0')
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++)
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1);
    }
    return 0;
}