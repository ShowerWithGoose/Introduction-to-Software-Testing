#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed, leading to compilation error if compiler enforces standard compliance]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes the last digit is the first non-zero after decimal, but ignores leading zeros after decimal point; also fails when input is "0.0" or similar, though problem states no trailing zeros]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should output only one digit before decimal and possibly digits after, not the whole string; e.g., "5.67" should become "5.67e0", but problem requires base to have one digit before decimal and rest after — however, this prints entire input including decimal point as-is, which violates scientific notation format]
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