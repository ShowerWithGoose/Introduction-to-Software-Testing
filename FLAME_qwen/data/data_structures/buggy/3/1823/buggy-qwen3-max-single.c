#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1; // @@ [If the input is like "0.001", then y becomes 3 (index of '1'), and p points to s[4], which is beyond the last digit, resulting in printing garbage or empty string. Also, if the number ends right after the first non-zero digit (e.g., "0.1"), p points to '\0', so ".%s" becomes ".", which violates the requirement of having one digit after decimal when base is decimal.]
        printf("%c.%se-%d",s[y],p,x+1);
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ [This prints all digits after the decimal point directly. However, if there are trailing zeros in the original input (which the problem states there aren't), it would be okay—but more critically, if the part after '.' is empty (shouldn't happen per problem), it could print nothing. However, the main issue is that this does not handle cases where the integer part has only one digit (e.g., "5.67") correctly—it outputs "5.67e0", but according to the problem, if there's only one digit before '.', and it's non-zero, the base can be just that digit without decimal? Actually, problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point". So "5.67" must become "5.67e0", which this does. But wait—the problem also says: "If it’s an integer, it contains only one significant digit without a decimal point." That applies only when there are no fractional digits? But input always has digits before and after decimal. So maybe this part is okay. However, the real bug is in the exponent calculation: for "123.45", it prints "1.2345e2", which is correct. But what about "1.23"? It prints "1.23e0"—correct. So logic seems okay. BUT: the problem says "all digits are significant (i.e., there are no trailing zeros after the decimal point)", so we don't have to worry about stripping zeros. However, the critical flaw is in the '0.xxx' branch as noted above.]
    }
    return 0;
}