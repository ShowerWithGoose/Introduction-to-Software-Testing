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
        
        if(s[i]=='-'&&s[i+1]>s[i-1]&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='9'&&s[i-1]>='0')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ The condition incorrectly requires all three character type ranges to be true simultaneously, but only one type should be checked. Also, the range checks are wrong (e.g., 'Z' >= 'A' is always true, but the condition should ensure both characters are in the same range, not all ranges).
        {
            len2=s[i+1]-s[i-1];

            //printf("%d\n",len2);
            
                for(j=0;j<len2-1;j++)
                {
                    printf("%c",s[i-1]+j+1);
                }
            
        }
        else printf("%c",s[i]); // @@ This prints the '-' character when expansion is not performed, but it also prints the '-' when expansion is performed (since the loop continues to i+1 after expansion, causing the next character to be printed again). Additionally, when expansion is performed, the '-' itself should not be printed, but here it is printed because the condition fails and falls to else.
    }
    
    
    
    return 0;
}