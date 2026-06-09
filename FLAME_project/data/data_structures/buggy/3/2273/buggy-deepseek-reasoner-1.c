#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++; // @@ The decimal point character is stored at c[i] but i is not incremented, causing the next character to overwrite it. This loses the dot and corrupts the index tracking.
    }
    i--; // @@ After overwriting, i now points to the last significant digit, but the original decimal point position is lost, leading to incorrect exponent and base formatting.
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ This branch handles the case with only one significant digit, but due to the missing dot, the condition i==(l+1) may incorrectly evaluate to false.
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ This always prints a decimal point after the first significant digit, even when there are no following digits, producing an unwanted '.' (e.g., "9." instead of "9").
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]); // @@ Similar issue: when the integer part is non-zero, the code always adds a decimal point and loops over remaining digits. But for inputs like "9" alone, this still prints "9." (though the problem may not have such cases).
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}