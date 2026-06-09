#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the primary logical errors are below. Also, note that the compilation error in the test environment ("gcc: not found") is unrelated to the code itself—it's an environment issue—but the code has logical flaws that would cause incorrect output.]
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is fundamentally flawed: it accesses s[i-1] when i=0 (undefined behavior), doesn't check character types (e.g., mixing letters and digits), and uses arbitrary range 26 which only applies to lowercase letters, not uppercase or digits. Also, it doesn't ensure both sides of '-' are same type or valid.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [This loop prints characters between s[i-1] and s[i+1], but only if the flawed condition passes. However, it fails to handle cases like 'a-R' correctly because type checking is missing. Also, when i=0, s[i-1] is s[-1] → undefined behavior.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}