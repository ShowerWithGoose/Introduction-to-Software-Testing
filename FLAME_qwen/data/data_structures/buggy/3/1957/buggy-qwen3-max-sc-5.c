#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes last digit is the first non-zero after decimal, but skips leading zeros improperly. Also fails when input is "0.0" or similar.]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Wrong output format: should normalize to one digit before decimal point, e.g., "5.3e0", not "5.3e0" as full string. Also doesn't remove decimal point properly for single-digit cases.]
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