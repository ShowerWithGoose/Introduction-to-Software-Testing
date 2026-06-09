#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and deprecated; however, the primary logical errors are below. Also, this may cause compilation issues with modern compilers that remove gets().]
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is flawed: it accesses s[i-1] when i=0 (undefined behavior), doesn't check character types (e.g., mixing letters and digits), and uses arbitrary range 26 which only applies to lowercase letters, not uppercase or digits. Also, s[i+1] may be '\0' leading to invalid comparisons.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [Same issues: relies on invalid assumptions about character ranges and types; also, if s[i+1] <= s[i-1], loop condition fails but expansion shouldn't occur anyway—however, the outer condition already incorrectly allows some invalid cases.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}