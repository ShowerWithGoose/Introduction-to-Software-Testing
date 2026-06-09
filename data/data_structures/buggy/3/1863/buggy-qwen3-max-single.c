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
        while(str[i]!='.') // @@ [If the input has no decimal point, this loop will run past the end of the string, causing undefined behavior. The problem states there are digits before and after the decimal point, but robust code should still validate input. However, the immediate error causing failure is likely due to 'gets'.]
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++) // @@ [Loop condition uses <= strlen(str)-1 which is equivalent to < strlen(str), but includes the null terminator index when j == strlen(str)-1 only if string length is considered correctly. However, more critically, this prints all characters except the first, including the decimal point, which violates output format (should omit the original decimal point).]
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0') // @@ [If all digits after "0." are zero (though problem states no trailing zeros and all digits are significant), this could run past the string end. But again, primary issue is use of 'gets'.]
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++) // @@ [Same issue as above: loop bound may include null terminator or miscount; also, exponent calculation is incorrect—it should be negative and based on position after leading zeros.]
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ [Exponent should be negative (e.g., e-3), but here it's printed as positive. Also, value i-1 is not the correct magnitude for negative exponents in scientific notation.]
    }
    return 0;
}