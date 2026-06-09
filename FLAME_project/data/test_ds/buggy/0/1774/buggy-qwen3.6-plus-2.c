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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ Logical error: The condition incorrectly checks character types. It requires s[i-1] to be lowercase (>= 'a') and s[i+1] to be <= 'Z', which fails for valid expansions like 'a-u' or 'B-F'. It should verify that both sides of '-' are of the same type (both lowercase, both uppercase, or both digits) and that s[i+1] > s[i-1].
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]);



    }





}