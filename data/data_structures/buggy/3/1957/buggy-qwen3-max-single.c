#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed, leading to compilation error if compiler enforces strict standard compliance]
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ [Incorrect logic: assumes the last digit is the first non-zero after decimal, but ignores leading zeros after decimal point; also fails when input is "0.0" or similar, though problem states no trailing zeros and at least one digit before/after decimal]
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ [Incorrect output format: should normalize to one digit before decimal; e.g., "5.67" should become "5.67e0", but this prints "5.67e0" only if input already has one digit before decimal — however, per problem, if there's only one digit before decimal it can be non-zero, so this case is acceptable only if input is like "5.67", but output must not include more than one digit before decimal in scientific notation base. However, the bigger issue is that this prints the whole string including the decimal part without ensuring only one digit before decimal — but since s[1]=='.', s[0] is the only digit before decimal, so this might be okay. Still, the real error is elsewhere.]
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