#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s);
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [The condition is logically incorrect: it requires the character before '-' to be both >= 'A' AND >= 'a', and the character after to be <= 'Z' AND <= 'z', which is impossible. It should check for same-type ranges (e.g., both lowercase, both uppercase, or both digits) separately. Also, it doesn't ensure that s[i-1] and s[i+1] are of the same category, nor does it check that s[i+1] > s[i-1].]
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]); // @@ [This prints characters one by one as the loop runs, but when an expansion occurs, it only prints the expanded middle characters without printing the starting character (s[i-1]) again, and also fails to skip the '-' and the next character properly. Moreover, the logic doesn't reconstruct the full string correctly—it mixes direct output with partial expansion, leading to missing or duplicated characters. The approach should build or print the entire result consistently, not mix per-character output with expansion blocks.]

    }





}