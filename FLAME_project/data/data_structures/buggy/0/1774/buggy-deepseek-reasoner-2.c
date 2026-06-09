#include <stdio.h>
#include<stdio.h> // duplicate include, but not an error
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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ Incorrect condition: requires both uppercase and lowercase simultaneously, making it always false. Should separately check lowercase, uppercase, or digit pairs.
        {
            int k=s[i+1]-s[i-1]; // @@ The expansion logic: loop prints middle characters only, missing the first and last characters; also using 'j<k' prints one fewer than needed. Additionally, the program does not output the expanded characters in place of the original substring; it just prints them separately.
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]);



    }





}