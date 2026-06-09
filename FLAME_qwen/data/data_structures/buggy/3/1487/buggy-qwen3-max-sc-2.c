#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, the logic fails for inputs like "123.45" because it assumes there's always a decimal point and mishandles cases with multiple digits before the decimal. Also, the program doesn't handle numbers without a decimal point at all, violating input assumptions.]
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2; // @@ [Assumes the input is always of the form "0.x...", but if the input is just "0" or malformed (though problem says valid), this skips incorrectly. Also, if input is "0.0...", it skips to i=2 which is after '.', but what if string length is less than 3?]
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2; // @@ [Exponent calculation is off: for "0.001", i becomes 4 (pointing to '1'), j=2, then prints e-3 → correct, BUT if all digits after are zero (not allowed per problem), still breaks. However, main issue: if input is "0.1", i=2 ('1'), j=0, prints e-1 → correct. So exponent logic seems okay, but initial i=2 assumes '.' is at index 1 always, which is true per input spec. So maybe not error here. But wait: what if input is "0."? Problem states there are digits after decimal, so safe. Still, the real bug is in the else branch.]
        
        printf("%c.", a[i]); // @@ [Always prints a decimal point even if there are no more digits after, but problem says there are digits after, so maybe okay. However, if only one digit total after leading zeros, e.g., "0.001", it prints "1." followed by nothing → violates output spec which says if base is decimal, must have one digit after decimal. But here it prints "1." with no following digits — that's invalid scientific notation per problem statement. Should only print decimal point if there are digits after.]
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1);
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]); // @@ [Always prints a decimal point, even if the number has only one digit before decimal and no digits after? But problem says there are digits after decimal. However, for input like "5.67", this prints "5.67e1" — but should be "5.67e0"! Because 5.67 is already normalized. The exponent should be 0, but code calculates j = i-1 where i stops at '.', so for "5.67", i starts at 0, enters loop: a[0]='5' != '.', so prints '5', then i=1, a[1]='.' → loop ends. j = 1-1 = 0 → prints e0 → correct. Wait, but what about "12.34"? Then: prints '1.', then enters while(a[i]!='.') → i=1, a[1]='2' != '.', so prints '2', then i=2, a[2]='.' → exit. j=2-1=1. Then prints remaining "34", so output is "1.234e1" — which is correct (12.34 = 1.234e1). So that seems okay. BUT: what if input is "123"? No decimal point! Problem states input has digits before AND after decimal point, so this case shouldn't occur. So maybe logic is okay? However, the first branch assumes "0.x", second assumes "x.y" with x≠0. But what if input is "10.5"? Then a[0]='1'≠'0', so goes to else. Prints '1.', then while(a[i]!='.'): i=1, a[1]='0'≠'.', so prints '0'; i=2, a[2]='.' → stop. j=2-1=1. Then prints "5". Output: "1.05e1" — correct. So why test failed? Wait, the compilation error in test suggests the program didn't even compile. But the given source uses 'gets', which in modern compilers causes warning or error unless allowed. However, the error message was "/bin/sh: 1: gcc: not found", which is environment issue, not code issue. But the problem says "Error type: Compilation Error", so likely the use of 'gets' is the culprit because it's removed in C11 and later. So the real error is using 'gets'. Also, the code doesn't handle the case when the number has more than one digit before decimal and the first digit is non-zero — but it does, as above. However, another critical flaw: in the else branch, it prints the first digit, then a '.', then all digits until '.', then all after. But what if the number is "1.0"? Problem says no trailing zeros, so "1.0" won't appear. So maybe the only real error is using 'gets', which causes compilation failure in strict environments. Additionally, the code doesn't include handling for numbers like "0.0" but problem states all digits are significant and no trailing zeros, so "0.0" is invalid input. So primary error: use of unsafe 'gets' function leading to compilation error in modern systems. Also, the first branch sets i=2 unconditionally, assuming the string is at least 3 characters long (like "0.x"), but if input is "0." (which shouldn't happen per problem), it would crash. But per problem, input has digits after decimal, so "0." alone is invalid. So main issue is 'gets'.]
        i=1;
         
        while(a[i] != '.')
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1;
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        printf("e%d", j);
    }
    return 0;
}