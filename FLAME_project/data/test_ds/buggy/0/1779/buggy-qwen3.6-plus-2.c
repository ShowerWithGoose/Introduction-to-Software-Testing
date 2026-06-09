#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++) // @@ [Accessing s[i-1] when i=0 and s[i+1] at the end causes out-of-bounds memory access. Should verify i>0 and s[i+1]!='\0' before accessing neighbors.]
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [Incorrect validation logic: fails to check if both characters are of the same type (digits, lowercase, or uppercase). The ASCII difference check <26 incorrectly allows cross-type expansions like '0-A'. Also, >=0 should be >0 as the right character must be strictly greater.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [Loop execution depends on the flawed condition above, leading to incorrect expansion for invalid ranges. The loop structure itself is fine but runs under wrong premises.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}