#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it doesn't handle trailing zeros or significant digits correctly as per problem constraints. Also, the logic below fails to normalize the number into proper scientific notation format.]
    int len=strlen(s);
    if(s[0]>'0'){ // @@ [This condition assumes the first digit is non-zero, but doesn't account for numbers like "123.45" where multiple digits precede the decimal point — it should normalize to one digit before decimal.]
        if(s[1]=='.'){ // @@ [Only handles single-digit integer part followed by decimal (e.g., "5.123"), but fails for multi-digit cases like "87899.999...".]
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This branch prints all digits without a decimal point and appends exponent, but scientific notation requires exactly one non-zero digit before decimal (e.g., "8.789..." not "87899...").]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [Assumes there's always a '.' after the first digit, which may not hold; also, loop may go out of bounds if no '.' exists.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This tries to find first non-zero digit for numbers starting with '0', but skips over '0' digits incorrectly and doesn't properly locate the decimal point relative to significant digits.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [Prints a decimal point even if next character is not a digit (e.g., end of string), and doesn't ensure only one digit before decimal.]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [Prints remaining characters including possible extra zeros or misplaced decimal, violating significant digit rules.]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect; for input like "0.00123", exponent should be -3, but this logic gives wrong offset due to miscounting positions.]
    }
    return 0;
}