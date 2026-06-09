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
        else if(s[0]>'0'&&s[1]!='.'){
            int tmp=0;
            while(s[1+tmp]!='.') tmp++;
            for(int i=0;i<len;i++){ // @@ This loop prints all digits without a decimal point, resulting in an incorrect base for numbers with multiple digits before the decimal point (e.g., "123.45" becomes "12345e2" instead of "1.2345e2"). It should print the first digit, then a decimal point, then the remaining digits excluding the original decimal point.
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
                if(s[tmp+1]!='\0') printf(".");
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]);
        printf("e-%d",tmp-1);
    }
    return 0;
}