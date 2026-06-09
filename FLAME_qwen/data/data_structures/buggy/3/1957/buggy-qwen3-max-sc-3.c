#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes last digit is the first non-zero after decimal, but ignores leading zeros after '0.'. Also fails when input is like "0.00123".]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should output only one digit before decimal (e.g., "1.23e0" for "1.23"), not the whole string. Also fails to remove decimal point properly.]
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
        printf("e%d",a-1); // @@ [Fails to handle cases where there are multiple digits before the decimal correctly; also outputs trailing digits without ensuring only significant digits are printed as per scientific notation rules.]
    }
    return 0;
}