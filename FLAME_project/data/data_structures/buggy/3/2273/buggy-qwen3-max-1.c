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
        i++; // @@ [This increment skips storing the '.' character in the array, causing misalignment in index calculations. The '.' is read but not stored because `i` is only incremented for non-'.' characters, so the '.' remains at position `i` but next char overwrites it. This leads to incorrect parsing of the input string.]
    }
    i--; // @@ [Because the loop condition reads until EOF and the last character (newline or EOF) may not be handled correctly, `i` might not represent the correct last index of the significant input. Also, due to the earlier bug, the string `c` is not properly null-terminated or aligned.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1)) // @@ [This condition checks if there's only one significant digit after leading zeros (e.g., "0.9"), but due to incorrect indexing from earlier bugs, `i` may not reflect the true end of input, causing wrong branch selection.]
        printf("%ce-%d",c[l],l);
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ [For cases like "0.9", this branch should not print a decimal point because there's only one significant digit; scientific notation should be "9e-1", not "9.e-1". The program always prints a decimal point when there are multiple digits, but fails to avoid it when only one digit exists.]
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]); // @@ [Similar issue: if the number has only one significant digit (e.g., "5.0" but per problem input there are no trailing zeros, so maybe "5." isn't valid input), but according to problem, if only one digit before decimal and it's non-zero, output should be just that digit without decimal. However, given input constraints, this branch may also incorrectly output a decimal point when unnecessary. But primary test case "0.9" doesn't hit this branch.]
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}