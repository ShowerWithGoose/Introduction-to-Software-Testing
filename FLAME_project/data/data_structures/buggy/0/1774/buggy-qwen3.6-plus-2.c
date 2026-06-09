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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [The condition logic is incorrect. It uses AND to combine uppercase and lowercase checks, which is impossible (a char cannot be both <= 'Z' and >= 'a' in a way that satisfies same-type expansion). It should check if both are lowercase, OR both are uppercase, OR both are digits. Also, it misses the digit case entirely.]
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]); // @@ [This prints the current character when the condition fails. However, if the previous character was part of an expansion range (e.g., the 'a' in 'a-c'), it has already been printed or handled incorrectly. More importantly, this approach prints characters one by one but fails to handle the character *after* the expansion range correctly in the flow, and doesn't account for the fact that the loop index `i` continues linearly while expansion consumes multiple logical characters. The main issue is the flawed condition above, but also this else block prints '-' itself if the condition fails, which is correct for non-expansion cases, but the logic for skipping expanded characters is missing.]



    }





}