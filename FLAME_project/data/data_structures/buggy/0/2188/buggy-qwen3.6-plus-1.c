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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ The condition checks if characters are within broad ranges but fails to ensure they are of the *same* specific type (e.g., both uppercase, both lowercase, or both digits) and fails to check if the end character is greater than the start character. For example, '0'-'A' would pass the digit/uppercase checks incorrectly if not strictly typed, and it doesn't verify s[i+1] > s[i-1]. Specifically, for '0-A', s[i-1]='0' and s[i+1]='A'. The condition `(s[i-1]>='0'&&s[i-1]<='9')` is true, so it enters the expansion block, which is incorrect because they are different types. Also, it doesn't check if s[i+1] > s[i-1].
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