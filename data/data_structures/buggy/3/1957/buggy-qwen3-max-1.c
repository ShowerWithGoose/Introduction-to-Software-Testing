#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11, causing compilation errors with modern compilers]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes last digit is first non-zero after decimal, fails for inputs like "0.00102"]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should output only one digit before decimal (e.g., "1.2e0" not "1.2e0" as full string)]
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