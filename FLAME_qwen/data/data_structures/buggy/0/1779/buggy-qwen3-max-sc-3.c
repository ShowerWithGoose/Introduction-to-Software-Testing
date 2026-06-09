#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the immediate error is logic-related. The main issue is accessing s[i-1] when i=0, leading to out-of-bounds read.]
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [Accesses s[i-1] when i=0, which is s[-1] — undefined behavior. Also, condition does not properly check character types (e.g., mixing letters and digits).]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++)
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}