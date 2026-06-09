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
        
        if(s[i]=='-'&&s[i+1]>s[i-1]&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='9'&&s[i-1]>='0')&&(s[i+1]<='z'&&s[i-1]>='a')) @@ [The condition incorrectly requires all three type ranges (uppercase, digit, lowercase) to be satisfied simultaneously due to using && between them. It should use separate conditions with || or individual checks like the reference program. Also, it does not ensure both characters are of the same type and valid before comparing. Additionally, accessing s[i-1] when i=0 leads to undefined behavior (reading before start of array).]
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