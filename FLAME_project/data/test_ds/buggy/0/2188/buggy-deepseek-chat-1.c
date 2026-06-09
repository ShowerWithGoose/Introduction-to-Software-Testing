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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition is incorrect: it does not ensure both characters are of the same type and that s[i+1] > s[i-1]. For example, it allows expansion between different types (e.g., '0' and 'A') and does not check that s[i+1] is greater than s[i-1]. Also, the third subcondition only checks s[i-1] for digits but not s[i+1].
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ This loop may produce incorrect characters if hc-s[i-1] is negative or zero, and it does not handle the case where s[i+1] <= s[i-1] (should not expand). Also, the loop condition uses <, which may miss the last character if the difference is an integer.
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