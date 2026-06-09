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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ Logical error: The condition incorrectly uses AND between uppercase and lowercase checks, making it impossible to satisfy. It should verify that both characters are of the same type (both lowercase, both uppercase, or both digits) and s[i-1] < s[i+1].
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++) // @@ Logical error: The loop bound j<k excludes the last character of the expansion range. It should be j<=k to correctly include s[i+1].
            {
                printf("%c",s[i-1]+j);
            }

        } // @@ Logical error: After printing the expanded characters, the code fails to skip s[i+1] in the next iteration, causing duplicate output. It should increment i and use continue.
else
printf("%c",s[i]);



    }





}