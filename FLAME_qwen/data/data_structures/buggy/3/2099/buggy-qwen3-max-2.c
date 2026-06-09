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
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This condition is redundant because it's already inside 'if(s[0]>'0')'; also, this branch doesn't handle numbers with more than one digit before the decimal point correctly.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [If there's no '.' in the string (though problem says there is), this loop will go out of bounds causing undefined behavior. Also, indexing assumes at least two characters before '.', which may not be true.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips leading zeros but fails when the first non-zero digit is after the decimal point and there are multiple zeros; also, it doesn't account for the position relative to the decimal point correctly.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [This prints a '.' even if the next character is not part of the significant digits (e.g., if it's the end or another zero).]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [This prints all remaining characters including the decimal point and any trailing zeros, violating the requirement that there are no trailing zeros and that only significant digits appear.]
        printf("e-%d",tmp-1); // @@ [The exponent calculation is incorrect: for input like "0.00123", tmp would be 3 (index of '1'), so exponent should be -3, but this gives -2.]
    }
    return 0;
}