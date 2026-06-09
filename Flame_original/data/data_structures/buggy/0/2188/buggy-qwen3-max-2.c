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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters around '-' are of the same type and valid; also accesses s[i+1] and s[i-1] without checking bounds (e.g., when i=0 or i=p-1), leading to undefined behavior. Additionally, the third part only checks s[i-1] is digit but ignores s[i+1].]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [Loop condition should be k <= hc - s[i-1] - 1 or similar to include the end character; currently misses the last character in expansion. Also, if hc < s[i-1], this loop may run with negative bound causing issues, though condition above tries (but fails) to prevent that.]
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