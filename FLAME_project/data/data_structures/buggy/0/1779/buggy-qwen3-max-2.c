#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is flawed: it assumes all valid ranges are within 26 characters and does not check character types (digit, lowercase, uppercase). It also accesses s[i-1] and s[i+1] without ensuring i>0 and s[i+1] exists, leading to undefined behavior. Additionally, it incorrectly allows cross-type expansions like '0'-'A'.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [This loop expands even when the surrounding characters are of different types or invalid, because the condition above doesn't validate character categories. Also, if s[i+1] <= s[i-1], the loop condition may still run due to prior flawed checks.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]); // @@ [This prints the current character normally, but when a '-' is encountered that shouldn't be expanded (e.g., due to type mismatch), the '-' itself should be printed. However, in cases where i points to '-', the else clause correctly prints '-', but the logic fails to skip printing the '-' when expansion occurs, because the expansion replaces the '-' but the original '-' is never printed — however, the real issue is that the condition is wrong, not this line per se. The main errors are in the condition and loop.]
    }

    return 0;
}