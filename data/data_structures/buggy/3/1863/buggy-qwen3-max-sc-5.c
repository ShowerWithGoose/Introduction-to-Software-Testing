#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
    if(str[0]!='0')
    {
        while(str[i]!='.') // @@ [If the input has no decimal point, this loop will run past the end of the string, causing undefined behavior. The problem states there is always a decimal point, but robust code should guard against missing '.']
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++) // @@ [Loop condition uses '<=', which may cause printing beyond valid digits if not careful; also inefficient to call strlen() repeatedly in loop condition]
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0') // @@ [If all digits after "0." are zero (though problem says no trailing zeros), this could run past string end; also, if input is exactly "0.0", behavior is undefined per problem constraints but code lacks safety]
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++) // @@ [Same issue as earlier: using '<=' with strlen()-1 may lead to off-by-one if not handled precisely; also repeated strlen() calls are inefficient]
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ [Exponent should be negative when number is less than 1 (like 0.00123 -> e-3), but here it prints positive (e2 for i=3 gives e2 instead of e-3). Logic error: should be e-(i-1) or similar negative form.]
    }
    return 0;
}