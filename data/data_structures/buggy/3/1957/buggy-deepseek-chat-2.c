#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ Error: This handles only the case where the number is like "0.xxx", but the exponent calculation is incorrect. For input "0.001", len-2 = 3, but the correct exponent should be -3 (since 0.001 = 1e-3). The code prints the last digit as the base, which is wrong; the base should be the first non-zero digit after the decimal point, not the last digit.
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ Error: For numbers like "1.23", this prints "1.23e0", but the base should have only one digit before the decimal point (which it does) and one digit after the decimal point (but here it prints all digits after the decimal point). The correct output should be "1.23e0" only if the number already has exactly one digit before and one after the decimal point; otherwise, it should be normalized (e.g., "12.3" should become "1.23e1", not "12.3e0").
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
        printf("e%d",a-1); // @@ Error: The exponent calculation a-1 is correct for numbers like "123.45" (a=3, exponent=2), but the output includes all digits after the decimal point without removing trailing zeros. However, the problem states there are no trailing zeros, so this part is acceptable. The main issue is that the base should have exactly one digit after the decimal point, but here it prints all digits after the decimal point (e.g., for "123.45", it prints "1.2345e2" instead of "1.2345e2" which is actually correct, but for "12.3" it prints "1.23e1" which is also correct). Actually, this branch seems correct for numbers with more than one digit before the decimal point. The real error is in the first two branches.
    }
    return 0;
}