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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition checks are incorrect. It fails to verify that the start and end characters are of the same type (e.g., both uppercase, both lowercase, or both digits) and that the start character is strictly less than the end character. For example, '0'-'A' would pass the digit check for s[i-1] but s[i+1] is not checked to be a digit, leading to invalid expansions. Also, it doesn't ensure s[i+1] > s[i-1].
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