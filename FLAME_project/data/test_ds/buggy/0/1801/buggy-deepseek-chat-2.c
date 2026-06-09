#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[1000]={0};
    int i,len1;
    scanf("%s",s);
    len1=strlen(s);
    for(i=0;i<len1;i++)
    {
        int len2=0,j=0;
        
        if(s[i]=='-'&&s[i+1]>s[i-1]&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='9'&&s[i-1]>='0')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ The condition incorrectly requires all three character type ranges to be true simultaneously, but only one type should be checked. Also, the range checks are wrong (e.g., 'Z' is less than 'a', so this condition will never be true for valid expansions).
        {
            len2=s[i+1]-s[i-1];

            //printf("%d\n",len2);
            
                for(j=0;j<len2-1;j++)
                {
                    printf("%c",s[i-1]+j+1);
                }
            
        }
        else printf("%c",s[i]); // @@ This prints the '-' character when expansion is performed, but the '-' should not be printed. Also, when expansion is performed, the characters before and after '-' are not printed correctly (the start character is missing, and the end character is printed later by this else branch).
    }
    
    
    
    return 0;
}