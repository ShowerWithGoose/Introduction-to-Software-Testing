#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ gets() is removed in C11 standard, causing compilation error; should use fgets() instead
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ Logical error: incorrectly assumes only one significant digit after decimal and miscalculates exponent for numbers like 0.12; also missing newline
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ Logical error: prints raw string which may not conform to output format; missing newline
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
        printf("e%d",a-1); // @@ Missing newline character at the end of output
    }
    return 0;
}