#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s);
    int len=strlen(s);
    if(s[0]>'0'){
        if(s[1]=='.'){
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ This condition is redundant because it's already inside the outer if(s[0]>'0') block. Also, the logic for handling numbers with more than one digit before the decimal point is incorrect; it does not correctly handle the case where the first digit is non-zero and there are multiple digits before the decimal point.
            int tmp=0;
            while(s[1+tmp]!='.') tmp++;
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf("."); // @@ This incorrectly adds a decimal point even if the next character is the end of string or a decimal point, and does not handle cases where the number has no digits after the first non-zero digit.
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]);
        printf("e-%d",tmp-1); // @@ The exponent calculation is incorrect; it should be based on the position of the decimal point relative to the first non-zero digit, not just tmp-1.
    }
    return 0;
}