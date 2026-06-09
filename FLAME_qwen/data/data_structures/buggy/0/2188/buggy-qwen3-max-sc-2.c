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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) @@ [The condition is logically incorrect: it does not ensure both characters around '-' are of the same type and valid. For example, it allows mixing uppercase and lowercase (e.g., 'A' and 'z'), and the digit check only validates s[i-1], not s[i+1]. Also, accessing s[i-1] when i=0 leads to out-of-bounds read.]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) @@ [Loop condition should be k <= hc - s[i-1] - 1 or similar to include the end character; current logic skips the last character. Also, if s[i+1] <= s[i-1], this loop may run with negative or zero iterations, but the condition above doesn't guarantee s[i+1] > s[i-1].]
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