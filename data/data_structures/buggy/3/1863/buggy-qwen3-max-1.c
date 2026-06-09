#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    if(str[0]!='0')
    {
        while(str[i]!='.') // @@ [If the input has no decimal point, this loop will run past the end of the string, causing undefined behavior. The problem states there are digits before and after the decimal point, but robust code should still guard against missing '.']
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++) // @@ [Loop condition uses <= strlen(str)-1 which includes the null terminator index; however, when j equals strlen(str)-1, str[j] is the last character before '\0', so this may be acceptable, but inefficient due to repeated strlen calls. More critically, it prints all non-'.' characters including those after '.', which is correct per logic, but note: this loop runs even if '.' is at position 1, which is okay. However, combined with earlier assumptions, risk remains if input format isn't strictly followed.]
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0') // @@ [If all digits after "0." are zero (though problem says no trailing zeros and all digits are significant), this could run past the string end. Also, if input is exactly "0.0", but problem states no trailing zeros, so maybe safe—but still lacks bounds check.]
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++) // @@ [Same issue as above: repeated strlen calls and potential off-by-one if not careful; also, if i+1 > strlen(str)-1, loop doesn't run, which is correct, but again assumes valid input.]
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ [Exponent should be negative when number is less than 1 (like 0.00123 -> e-3), but here it prints e2 for "0.00123" (since i=3, i-1=2), which is wrong. Should be e-(i-1) or similar. This is a logical error causing incorrect exponent sign.]
    }
    return 0;
}