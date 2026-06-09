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
        i++; // @@ [This skips the '0' before the decimal point, but assumes input always starts with "0."; however, it doesn't verify that the next character is '.', leading to incorrect index handling if input format deviates slightly or if there's no decimal point. Also, the loop condition below may access out-of-bound memory.]
        while(s[i+1]=='0') // @@ [If the string ends right after "0.", this accesses s[len], which is '\0', and comparing it to '0' may lead to skipping non-existent zeros. Also, if there are no non-zero digits after decimal, this loop may run past the string end.]
            i++;
        printf("%c.",s[i+1]); // @@ [If all digits after decimal are zero (which shouldn't happen per problem statement, but code doesn't validate), i+1 could be beyond string length, causing undefined behavior. Also, per problem, trailing zeros don't exist, but this logic fails if the first non-zero digit is at the very end.]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i); // @@ [Exponent calculation is off: for "0.00123", i becomes 2 (after two zeros), so exponent should be -3, but this prints e-2. Correct exponent is -(number of leading zeros after decimal + 1).]
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1) // @@ [Loop condition checks s[i+1] before ensuring i+1 is within bounds; also, if there's no decimal point in the number (e.g., integer input like "123"), this loop exits when i==len-1, but the following logic assumes a decimal point exists.]
            i++;
        if(i==len-1)
        {
        while(s[len-1-k]=='0') // @@ [Problem states there are no trailing zeros after decimal, but this handles trailing zeros as if they exist. Also, if input has no decimal point (e.g., "123"), this tries to remove trailing zeros from an integer, which contradicts problem assumptions.]
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++) // @@ [Indexing is confusing and likely incorrect. If input is "123.45", i would be 2 (index of '.'), but this branch is only taken if no '.' found (i==len-1), so mixing logic for numbers with and without decimal points.]
            printf("%c",s[j]);
        }
        printf("e%d",i); // @@ [If input is an integer like "123", scientific notation should be "1.23e2", but this may output wrong base or exponent due to flawed logic in this branch.]
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i); // @@ [For input like "123.45", i is index of '.', which is 3, so exponent printed is 3, but correct exponent is 2 (since 1.2345e2). Should be i-1, not i.]
        }
    }
    return 0; 
}