#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    if(str[0]!='0')
    {
        while(str[i]!='.') // @@ [If the input has no decimal point, this loop will run past the end of the string, causing undefined behavior. The problem states there is always a decimal point, but robustness is still an issue. However, the primary error is the use of 'gets'.]
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++) // @@ [Loop condition uses <= strlen(str)-1 which is equivalent to < strlen(str), but includes the null terminator index incorrectly if not careful. More critically, this prints all characters except the null terminator, including the decimal point again, which violates output format (should skip the '.').]
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0') // @@ [If all digits after "0." are zero (though problem says no trailing zeros, so at least one non-zero exists), but if input ends right after zeros, this may go out of bounds. Still, main issue remains 'gets'.]
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++) // @@ [Same issue as above: loop goes up to strlen(str)-1 inclusive, which is correct for last character, but logic may miscount if decimal point position isn't handled properly. However, the critical error causing compilation failure is 'gets'.]
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ [Exponent should be negative when number is less than 1 (like 0.00123 -> e-3), but here it prints e2 for "0.00123" (i=3, so i-1=2), which is wrong sign. This is a logical error, but the reported error type is Compilation Error, so focus is on 'gets'.]
    }
    return 0;
}