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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters are of the same type and valid, and it doesn't check that s[i+1] > s[i-1]. Also, it accesses s[i+1] without checking if i+1 is within bounds.]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [This loop runs even when the range is invalid (e.g., when s[i+1] <= s[i-1]), and it doesn't verify that both ends are of the same category (digit, lowercase, uppercase). Additionally, hc-s[i-1] could be negative or based on mismatched types (e.g., '0' to 'A'), leading to garbage output.]
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