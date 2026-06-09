#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic for parsing and converting to scientific notation is fundamentally flawed]
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++) // @@ [Assumes input always starts with "0."; fails if there are multiple digits before decimal or if input doesn't start with '0']
        {
            a--;
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1)
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j];
                    str[1]='.'; // @@ [Incorrectly places '.' at index 1 regardless of how many digits follow; also overwrites potential digit at str[1]]
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ [Loop starts from strlen(s), which is out of bounds (valid indices are 0 to strlen(s)-1); also logic for shifting digits is incorrect]
        {
            if(s[i]!='.') // @@ [Accesses s[strlen(s)], which is '\0', not a valid digit; leads to undefined behavior]
            {
                str[i]=s[i]; // @@ [Copies characters to wrong positions in str; does not construct normalized scientific base correctly]
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ [Arbitrary indexing; does not produce a single non-zero digit before decimal point as required]
                    a++; // @@ [Only increments exponent by 1 regardless of actual position of decimal point; should be based on number of digits before decimal minus 1]
                str[0]=s[0];
                str[1]=s[i]; // @@ [Assigns '.' to str[1], but s[i] is '.', which is correct character but placed without ensuring proper normalization]
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ [Output format may include trailing zeros or incorrect decimal placement; exponent 'a' is computed incorrectly in both branches]
    return 0;
}