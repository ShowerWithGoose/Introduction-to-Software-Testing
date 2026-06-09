#include <stdio.h>
#include<stdio.h> // @@ [duplicate include of stdio.h is unnecessary but not a compilation error; however, the real issue is use of gets()]
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
int main()
{
    gets(s); // @@ [gets() is unsafe and has been removed from newer C standards; many compilers will refuse to compile it, causing a compilation error]
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [logic error: condition incorrectly requires both uppercase AND lowercase ranges simultaneously, which is impossible; also accesses s[i-1] when i=0 leading to undefined behavior]
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