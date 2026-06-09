#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers that remove gets() from stdio.h]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes last digit is the first non-zero after decimal, fails for inputs like "0.00123"]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should normalize to one digit before decimal, e.g., "5.0e0" not "5.0e0" as full string]
    } else if(s[0]!='0'&&s[1]!='.'){
        for(int i=0;i<len;i++){
            if(s[i]=='.'){
                a=i;
            }
        }
        printf("%c.",s[0]);
        for(int i=1;i<len;i++){
            if(s[i]!='.'){
                printf("%c",s[i]);
            }
        }
        printf("e%d",a-1);
    }
    return 0;
}