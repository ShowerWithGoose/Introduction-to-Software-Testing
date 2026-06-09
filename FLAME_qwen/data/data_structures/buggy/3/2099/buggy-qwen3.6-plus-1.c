#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ 'gets' is deprecated and removed in C11, causing a compilation error in modern/strict environments; use 'fgets' instead.
    int len=strlen(s);
    if(s[0]>'0'){
        if(s[1]=='.'){
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ Logical error: finds the index of '.', but the subsequent code fails to correctly format the base for numbers >= 10.
            for(int i=0;i<len;i++){ // @@ Logical error: prints all digits concatenated without inserting a decimal point after the first digit, violating the output format.
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp); // @@ Logical error: the exponent should be 'tmp-1' (number of digits before the decimal point minus 1), not 'tmp'.
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