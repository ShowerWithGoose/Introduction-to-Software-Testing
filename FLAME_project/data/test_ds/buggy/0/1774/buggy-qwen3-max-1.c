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
        if(s[i]=='-'&&(s[i+1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='z'&&s[i-1]>='a')) // @@ [The condition incorrectly requires both uppercase and lowercase ranges simultaneously, which is impossible. It should check each type (lowercase, uppercase, digit) separately and ensure both sides are of the same type. Also, it doesn't check digits at all.]
        {
            int k=s[i+1]-s[i-1];
            for(int j=1; j<k; j++)
            {
                printf("%c",s[i-1]+j);
            }

        }
else
printf("%c",s[i]); // @@ [This prints characters one by one as the loop runs, but when an expansion occurs, it only prints the expanded part without printing the leading character (s[i-1]) or handling the rest of the string correctly. Also, after expanding, the '-' and the next character should not be printed again, but this logic doesn't skip them.]


    }





}