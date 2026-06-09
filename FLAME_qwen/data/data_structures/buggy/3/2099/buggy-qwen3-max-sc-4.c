#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers]
    int len=strlen(s);
    if(s[0]>'0'){
        if(s[1]=='.'){
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [Redundant condition: s[0]>'0' is already checked in outer 'if']
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [Potential out-of-bounds access if input has no decimal point]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [Incorrect logic: skips valid digits like '0' after decimal when leading zeros exist]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf(".");
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [May print '.' again if original string contains it after significant digit]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect for cases like "0.001" (should be e-3, not e-2)]
    }
    return 0;
}