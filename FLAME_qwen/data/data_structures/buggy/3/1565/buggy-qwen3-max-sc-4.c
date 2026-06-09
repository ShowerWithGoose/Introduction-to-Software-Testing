#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++)
        {
            a--;
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1)
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j];
                    str[1]='.';
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ [Loop starts at strlen(s), which is the null terminator index; accessing s[i] here reads past the last character, leading to undefined behavior. Should start at strlen(s)-1.]
        {
            if(s[i]!='.') // @@ [When i == strlen(s), s[i] is '\0', not '.', so this condition may incorrectly process the null terminator as a digit.]
            {
                str[i]=s[i]; // @@ [Writing to str[i] where i can be up to strlen(s) may write beyond the intended output format and leave earlier indices uninitialized.]
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ [This loop copies digits starting from s[1] into str[2..i], but logic is flawed: it doesn't correctly normalize to one non-zero digit before decimal. Also, str[0] and str[1] are set after, overwriting possibly needed data.]
                    a++; // @@ [Incrementing 'a' once per '.' found, but exponent calculation is incorrect; should be based on position of first significant digit relative to decimal point.]
                str[0]=s[0];
                str[1]=s[i]; // @@ [Assigning '.' to str[1] only if there are more digits, but this assignment happens unconditionally after the loop, even if no fractional part exists. Also, if the number has no fractional part (e.g., "123"), this logic fails.]
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ [The string 'str' may not be null-terminated, leading to undefined behavior when printed. Also, the constructed scientific notation often does not follow the required format (e.g., missing decimal point when needed, wrong exponent).]
    return 0;
}