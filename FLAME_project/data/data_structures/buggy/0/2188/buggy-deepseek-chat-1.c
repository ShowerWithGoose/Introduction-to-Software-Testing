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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition does not properly check that both characters are of the same type and that the character after '-' is greater than the one before. It also lacks range checks for the second character (e.g., s[i+1] should be checked against 'Z' and 'z' and '9' respectively). Additionally, it does not ensure s[i-1] and s[i+1] are within valid ranges for expansion.
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ The loop condition uses hc-s[i-1] which may be negative or zero, causing incorrect or no output. It also does not check that s[i+1] > s[i-1] before expanding.
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