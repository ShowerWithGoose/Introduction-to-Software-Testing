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
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [Redundant condition: 's[0]>'0'' is already checked in the outer 'if'; also, this branch does not handle numbers with more than one digit before the decimal point correctly.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [Potential infinite loop or out-of-bounds access if there's no '.' in the string (though problem states input always has a decimal point).]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips leading zeros but fails to account for the case where the first non-zero digit is immediately after the decimal point (e.g., "0.5"), leading to incorrect exponent calculation.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [Incorrectly prints a decimal point even if there are no more digits after the first significant digit, violating the output format which requires no trailing zeros or unnecessary decimal points.]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [Prints all remaining characters including the decimal point if it hasn't been skipped, which can result in malformed scientific notation like "5..123".]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect: for input "0.005", tmp=3 (index of '5'), so exponent becomes -2, but correct exponent should be -3. Should be -(tmp - 1) only if counting digits after decimal before first non-zero, but logic doesn't align.]
    }
    return 0;
}