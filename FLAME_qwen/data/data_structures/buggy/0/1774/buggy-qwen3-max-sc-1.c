#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, the problem expects reading with scanf like the reference]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [Incorrect condition: it requires both uppercase AND lowercase conditions to be true simultaneously, which is impossible; also missing digit handling and proper same-type check]
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