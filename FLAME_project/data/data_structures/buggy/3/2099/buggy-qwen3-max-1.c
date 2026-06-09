#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic fails to correctly parse scientific notation for numbers >= 10]
    int len=strlen(s);
    if(s[0]>'0'){ // @@ [This condition only checks if first digit > '0', but doesn't handle cases like "10.5" correctly where multiple digits exist before decimal]
        if(s[1]=='.'){ // @@ [Assumes that if second character is '.', then it's already in normalized form, but ignores cases like "5." or longer decimals]
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This branch removes the decimal point and prints all digits, but fails to format base as single digit followed by decimal and rest]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [Incorrectly assumes there is always a '.' after the first digit; will crash if no '.' exists (e.g., integer input)]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [Skips leading zeros including '0' before decimal, but logic for exponent and decimal placement is flawed for inputs like "0.001"]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ [Prints '.' even if next char is not a digit (e.g., end of string), causing incorrect output]
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [Prints remaining characters including non-digit or extra decimals, not filtering out original decimal point properly]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect; for "0.001", should be e-3, but this gives e-2 due to off-by-one error]
    }
    return 0;
}