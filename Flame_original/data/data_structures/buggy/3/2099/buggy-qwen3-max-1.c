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
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This condition is redundant because it's already inside 'if(s[0]>'0')'; also, this branch doesn't handle numbers with more than one digit before the decimal correctly in all cases.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [If there's no '.' in the input (though problem states there is), this loop will go out of bounds causing undefined behavior. Also, variable-length logic assumes at least two digits before '.', which may not hold.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips leading zeros correctly, but fails to account for the case where the first non-zero digit is immediately after the decimal (e.g., "0.1"), leading to incorrect exponent calculation.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [This prints a decimal point even if there are no more digits after the first non-zero digit, violating the requirement that trailing zeros are not present and possibly adding an unnecessary decimal point.]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [This prints all remaining characters including the decimal point if it hasn't been skipped, which can result in malformed scientific notation like "1..23".]
        printf("e-%d",tmp-1); // @@ [The exponent calculation is incorrect. For input like "0.001", the first non-zero is at index 3 ('1'), so exponent should be -3, but this gives -(3-1) = -2.]
    }
    return 0;
}