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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters are of the same type (e.g., both uppercase, both lowercase, or both digits), and it lacks bounds checking for s[i+1] in digit/lowercase cases. Also, accessing s[i-1] when i=0 leads to undefined behavior.]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [Loop condition should be k <= hc - s[i-1] - 1 or similar to include the end character; current logic misses the last character. Also, if hc < s[i-1], this could cause negative loop bounds or infinite loops, though the flawed condition above may prevent that partially.]
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