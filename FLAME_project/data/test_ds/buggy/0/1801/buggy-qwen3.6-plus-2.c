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
        
        if(s[i]=='-'&&s[i+1]>s[i-1]&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='9'&&s[i-1]>='0')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ The condition incorrectly uses && to combine mutually exclusive character range checks, making it logically impossible to be true. It should use || to check if both characters are lowercase, uppercase, or digits respectively, e.g., ((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9')).
        {
            len2=s[i+1]-s[i-1];

            //printf("%d\n",len2);
            
                for(j=0;j<len2-1;j++)
                {
                    printf("%c",s[i-1]+j+1);
                }
            
        }
        else printf("%c",s[i]);
    }
    
    
    
    return 0;
}