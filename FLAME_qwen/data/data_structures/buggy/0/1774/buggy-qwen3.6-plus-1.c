#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern compilers; use fgets() instead.
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ Logical error: condition incorrectly mixes uppercase and lowercase bounds, fails to verify that both characters are of the same type, and omits the required s[i-1] < s[i+1] check.
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++) // @@ Logical error: loop condition j<k excludes the final character of the expansion range; it should be j<=k to correctly include the end character.
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]);



    }





}