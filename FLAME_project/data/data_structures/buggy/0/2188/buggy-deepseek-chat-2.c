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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ Error: The condition does not properly check that both characters are of the same type and that the character after '-' is greater than the one before. It also does not check that s[i+1] is within the same range as s[i-1] (e.g., for digits, it only checks s[i-1] but not s[i+1]). Additionally, it lacks the requirement that s[i+1] > s[i-1] for expansion to occur.
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ Error: The loop condition uses hc-s[i-1] which may be negative or zero if s[i+1] <= s[i-1], leading to incorrect or no output. Also, the loop should only execute when s[i+1] > s[i-1], but this is not guaranteed by the condition above.
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