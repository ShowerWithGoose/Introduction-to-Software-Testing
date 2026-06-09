#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++; // @@ [This skips the '0', but then the loop condition checks s[i+1], which may go out of bounds if input is "0.0" or similar short forms. Also, logic assumes at least two characters after '0', which isn't guaranteed.]
        while(s[i+1]=='0') // @@ [Accesses s[i+1] without ensuring i+1 < len, leading to potential buffer overread. Also, if all digits after decimal are zero (which shouldn't happen per problem, but code doesn't validate), this may run past string end.]
            i++;
        printf("%c.",s[i+1]); // @@ [If the non-zero digit is the last character (e.g., "0.001"), this prints it with a decimal point even when no following digits exist, violating output spec that says no trailing zeros and decimal only if more than one significant digit. Also, if i+1 >= len, this is undefined behavior.]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i); // @@ [Exponent calculation is incorrect. For "0.001", expected exponent is -3, but i would be 2 (after skipping two zeros), so e-2 is printed instead of e-3. Should be i+1 or based on position relative to decimal.]
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1) // @@ [Loop condition checks s[i+1] before verifying i+1 is valid; also, if there's no decimal point in input (e.g., "123"), this loop exits with i = len-1, but then the following logic incorrectly assumes decimal exists. Problem states input has digits before AND after decimal, so '.' must exist, but code doesn't handle missing '.' safely.]
            i++;
        if(i==len-1)
        {
        while(s[len-1-k]=='0') // @@ [Problem states no trailing zeros after decimal, so this loop is unnecessary and dangerous: if input has no decimal (contrary to spec), or if k grows too large, it reads before start of string. Also, s[len-1-k] when k increases may access s[-1].]
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++) // @@ [Indexing logic is flawed. i is len-1 here, so i+1-k = len - k, but j starts at 1 and goes to len-k-1. However, original string includes a decimal point somewhere, which hasn't been accounted for in this branch. This branch seems intended for integers, but problem states input always has decimal point.]
            printf("%c",s[j]);
        }
        printf("e%d",i); // @@ [If input is like "123.45", this branch shouldn't execute, but if it does (e.g., due to missing '.'), exponent is wrong. Even if valid, exponent should be number of digits after first minus one, not i.]
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i); // @@ [Exponent is i, which is the index of the character before '.', so for "123.45", i stops at index 2 (s[3]=='.')? Actually, loop condition is while(s[i+1]!='.'), so when s[i+1]=='.', loop stops, so i is index before '.', meaning for "12.3", i=1, exponent=1, which is correct (1.23e1). But if input is "1.23", i=0, exponent=0 → "1.23e0", but expected is "1.23" without exponent? No—problem says scientific notation always includes e. However, reference program uses i-1. Wait: in "123.45", decimal is at index 3, so digits before: 3, so exponent should be 2. In this code, i increments until s[i+1]=='.', so when i=2, s[3]=='.', so i=2, exponent=2 → correct. So this part might be okay. But what if input is "1.0"? Problem says no trailing zeros, so "1.0" won't appear. So maybe this branch is mostly correct, but the other branches have critical errors.]
        }
    }
    return 0; 
}