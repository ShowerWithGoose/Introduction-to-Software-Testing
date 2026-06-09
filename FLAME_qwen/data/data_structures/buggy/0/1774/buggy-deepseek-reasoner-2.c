#include <stdio.h>
#include<stdio.h> // duplicate include, not an error
#include<string.h>
#include<stdlib.h>
#include<math.h> // unnecessary but not an error
char s[200];
int main()
{
    gets(s); // @@ [gets is unsafe and deprecated; can cause buffer overflow. Should use fgets instead.]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [Condition is logically impossible because it requires both uppercase and lowercase ranges simultaneously. Should check that s[i-1] and s[i+1] are both uppercase, or both lowercase, or both digits, and that s[i-1] < s[i+1]. Also missing bounds checks for i-1 and i+1.]
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