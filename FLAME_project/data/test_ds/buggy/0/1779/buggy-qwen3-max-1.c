#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is flawed: it assumes all valid ranges are within 26 characters and does not check character types (digit, lowercase, uppercase). It also accesses s[i-1] and s[i+1] without ensuring i>0 and s[i+1] exists, leading to undefined behavior. Additionally, it expands even across different character categories like '0' to 'A'.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [This loop expands based only on ASCII difference, ignoring whether the endpoints are of the same type (e.g., digit-digit, letter-letter). This causes incorrect expansion such as from '0' to 'A', which should not be expanded.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}