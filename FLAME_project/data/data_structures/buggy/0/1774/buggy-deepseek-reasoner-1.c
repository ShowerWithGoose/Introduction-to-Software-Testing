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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [Condition is logically impossible because it requires both uppercase and lowercase ranges simultaneously; should check either both lowercase, both uppercase, or both digits.]
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j); // @@ [Only prints inner characters; missing left and right characters of the expansion range. Should also print s[i-1] before the loop and s[i+1] after.]
            }

        }
else
printf("%c",s[i]);



    }





}