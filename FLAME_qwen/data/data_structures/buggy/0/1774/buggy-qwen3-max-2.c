#include <stdio.h>
#include<stdio.h> // @@ [duplicate include of stdio.h is unnecessary but not a compilation error; however, the real issue is use of unsafe gets()]
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ [gets() is unsafe and has been removed from modern C standards; many compilers reject it, causing compilation error]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [logic error: condition requires both uppercase AND lowercase ranges simultaneously, which is impossible; also fails to check digit range and proper type matching]
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