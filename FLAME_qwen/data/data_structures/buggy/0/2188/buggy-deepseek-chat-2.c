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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition does not properly check that both characters are of the same type and that the character after '-' is greater than the one before. It also lacks range checks for lowercase and digits, and does not ensure s[i-1] < s[i+1].
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ The loop condition should be k <= hc - s[i-1] to include all characters in between, and the loop variable k is declared twice (int k=1; and then for(k=1;...)).
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