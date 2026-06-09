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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition is incorrect: it does not ensure both characters are of the same type and that s[i+1] > s[i-1]. For example, it treats "0-A" as expandable because s[i-1]>='0' is true, but the characters are different types. Also, it lacks the check s[i+1] > s[i-1] for digits and uppercase.
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ This loop may produce incorrect characters if hc-s[i-1] is negative or zero, and it does not handle the case where expansion should not occur (e.g., when characters are not of the same type or s[i+1] <= s[i-1]).
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