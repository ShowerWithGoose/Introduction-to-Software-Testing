#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, the condition logic for expansion is incorrect—it uses && between uppercase and lowercase checks, which can never be true simultaneously.]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [Logical error: This condition requires the characters around '-' to be both uppercase AND lowercase at the same time, which is impossible. It should check each category (uppercase, lowercase, digit) separately with OR conditions. Also, missing bounds checks for i-1 and i+1 possibly going out of array bounds.]
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