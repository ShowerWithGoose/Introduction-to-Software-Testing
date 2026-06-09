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
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This condition is redundant because it's already inside 'if(s[0]>'0')'; also, this branch doesn't handle cases where the number has more than one digit before the decimal correctly.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [If there is no '.' in the string (which shouldn't happen per problem statement but still), this loop will go out of bounds causing undefined behavior. Also, variable-length logic assumes '.' exists after index 1.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips leading zeros correctly, but fails when input is like "0.0" (though problem says all digits are significant, so maybe not). However, if the first non-zero digit is at position 2 or beyond, exponent calculation may be off.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [This prints a '.' even if the rest of the digits are empty or only contain the decimal point, which may result in trailing '.' or incorrect format.]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [This prints everything after the first significant digit, including the decimal point if it hasn't been skipped, leading to malformed output like '5..123'.]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect: for input "0.005", first non-zero is at index 3 ('5'), so exponent should be -3, but this gives e-2. Correct exponent is -(position_of_first_nonzero - 1) if counting from after '0.'.]
    }
    return 0;
}