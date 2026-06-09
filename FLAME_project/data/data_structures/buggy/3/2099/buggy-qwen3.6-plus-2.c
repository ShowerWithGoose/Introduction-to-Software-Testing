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
            for(int i=0;i<len;i++){
                if(i==0) printf("%c",s[i]); // @@ [The base in scientific notation must have exactly one non-zero digit before the decimal point. The original code printed all digits before the decimal point, violating the format.]
                else if(s[i]!='.') printf("%c",s[i]);
            }
            if(tmp > 0) printf("."); // @@ [If there are digits after the first significant digit, a decimal point is required to separate the base's integer and fractional parts.]
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