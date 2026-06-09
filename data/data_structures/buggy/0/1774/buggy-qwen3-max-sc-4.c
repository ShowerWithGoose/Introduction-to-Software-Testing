#include <stdio.h>
#include<stdio.h> // @@ [duplicate include; not a compilation error but unnecessary]
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ [uses unsafe and deprecated function 'gets' which may cause buffer overflow; also, in some environments, 'gets' is removed entirely causing compilation error]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [logic error: condition requires both uppercase AND lowercase ranges simultaneously, which is impossible; also fails to check digit ranges and proper type matching]
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