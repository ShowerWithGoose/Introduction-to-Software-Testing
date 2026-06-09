#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char s[105];
    int i,j,k;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, the program logic fails to handle cases where there's no decimal point in input, leading to undefined behavior or no output.]
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            if(s[i-1]!='0')
            {
                printf("%c.",s[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
            }
            else
            {
                for(j=2;j<strlen(s);j++)
                {
                    if(s[j]!='0')
                    {
                        k=j;
                        break;
                    }
                }
                for(j=k;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ [Incorrect exponent calculation: for input like "0.00123", k=4 (index of '1'), but exponent should be -3, not -(4-1)=-3? Wait: positions: s[0]='0', s[1]='.', s[2]='0', s[3]='0', s[4]='1' → leading zeros after decimal = 2, so exponent = -3. k=4, so k-2 = 2 zeros, exponent = -(k-1) = -3 → actually correct? But what if all digits after decimal are zero? Also, loop may not set 'k' if no non-zero found, leading to uninitialized 'k' usage.]
            }
        }
    } // @@ [If input has no decimal point (e.g., "123"), the loop never enters the 'if(s[i]=='.')' block, so nothing is printed — violates problem requirement that input always has digits before and after decimal point, but program must still handle spec. However, problem states input "has digits before and after the decimal point", so maybe no '.' case shouldn't occur. But reference program handles it. More critically: when s[0]=='0' and decimal at i=1, the 'else' branch assumes j starts at 2, but if string length is 2 (e.g., "0."), then j=2 >= strlen(s), loop doesn't run, 'k' remains uninitialized, leading to undefined behavior when used in printf.]
    return 0;
}