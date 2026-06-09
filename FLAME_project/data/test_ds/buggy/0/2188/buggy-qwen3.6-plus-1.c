#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char hc;
    char s[100];
    int j=0,i=0;
    scanf("%s",s);
    int p=strlen(s);
    for(i=0;i<p;i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition incorrectly checks character ranges. It fails to ensure both sides of '-' are of the same type (all uppercase, all lowercase, or all digits) and does not verify that the right character is strictly greater than the left character. This causes invalid expansions like '0-A' to be processed.]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++)
            {
                printf("%c",s[i-1]+k);
            }
            
        }
        else
        {
            printf("%c",s[i]);
        }
    }
}