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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters are of the same type (e.g., both uppercase, both lowercase, or both digits), and it doesn't check that s[i+1] > s[i-1]. Also, accessing s[i-1] when i=0 leads to out-of-bounds read.]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [Loop condition should be k <= hc - s[i-1] to include the end character; also, if hc < s[i-1], this loop may run incorrectly or cause undefined behavior. Additionally, s[i-1] may be invalid when i=0.]
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