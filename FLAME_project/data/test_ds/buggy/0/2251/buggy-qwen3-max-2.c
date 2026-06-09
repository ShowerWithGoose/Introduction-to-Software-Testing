#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ [The condition checks only the lower bound for s[i-1] and upper bound for s[i+1], but does not ensure both are digits. For example, s[i-1] could be 'a' (>= '0') and s[i+1] could be '5' (<= '9'), which would incorrectly pass the digit check. Both characters must be within the same category.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [Same issue: only checks s[i-1] >= 'a' and s[i+1] <= 'z', but doesn't ensure s[i-1] <= 'z' or s[i+1] >= 'a'. So a mix like 'Z'-'b' might incorrectly pass this condition.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [Same issue: missing bounds check on both ends. s[i-1] could be '{' (>= 'A') and s[i+1] could be 'C' (<= 'Z'), which is invalid but would pass.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}