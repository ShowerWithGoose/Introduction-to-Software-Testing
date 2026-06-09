#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    int len=strlen(s);
    if(s[0]>'0'){
        if(s[1]=='.'){
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This condition is redundant because it's already inside 'if(s[0]>'0')'; also, this branch assumes there is a decimal point later, but input format guarantees one, yet indexing may go out of bounds if not handled carefully.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [Potential infinite loop or buffer overflow if the string does not contain a '.', though problem states it will; however, no bounds check on '1+tmp < len'.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips leading zeros correctly, but if the number is like "0.000...", and all digits after are zero (though problem says no trailing zeros, but leading zeros after decimal are allowed), this may not find any digit > '0', leading to undefined behavior as 'tmp' remains 0 and later accesses s[tmp+1].]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [This prints a '.' even if the rest of the digits are empty or only zeros, which may violate the requirement of no trailing zeros; also, if tmp+1 is beyond string length, it's undefined behavior.]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [This prints all remaining characters including the decimal point if not skipped, which is incorrect because the decimal point should not appear in the mantissa part of scientific notation.]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect: for input "0.00123", first non-zero is at index 3 ('1'), so exponent should be -3, but tmp=3 => e-2, which is wrong. Correct exponent is -(position_of_first_nonzero_after_decimal) = -(i - 1) where i is index of first non-zero after '0.'.]
    }
    return 0;
}