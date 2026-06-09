#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed entirely, leading to compilation error if compiler adheres strictly to standard]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes last digit is the first non-zero after decimal, but ignores leading zeros after decimal point; also fails when input is "0.0" or similar, though problem states no trailing zeros]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should normalize to one digit before decimal; e.g., "5.67" should become "5.67e0", but this prints "5.67e0" only if input already has one digit before '.', but problem requires normalized scientific notation with exactly one non-zero digit before decimal unless it's zero case]
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