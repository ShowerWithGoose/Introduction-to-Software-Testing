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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [The condition is logically incorrect: it requires both uppercase and lowercase ranges simultaneously, which is impossible. Also, it doesn't check digit ranges or ensure both sides are the same type.]
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]); // @@ [This prints characters one by one without handling the full expansion correctly; also, when an expansion occurs, the '-' and surrounding characters are not properly skipped or replaced, leading to duplication or omission. Additionally, the loop does not update the string in-place nor adjust the index to skip expanded parts, causing misalignment.]


    }





}