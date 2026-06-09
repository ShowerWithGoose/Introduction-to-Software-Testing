#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s);
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Error: This loop condition does not check if the characters around '-' are of the same type and in ascending order, nor does it handle cases where expansion should not occur (e.g., B-e). It also does not validate that s[i-1] and s[i+1] are within valid ranges [a-z], [A-Z], [0-9].
            {
                m[j]=m[j-1]+1; // @@ Error: This incorrectly uses m[j-1] which may be uninitialized or from a previous character, instead of using the correct starting character s[i-1] and incrementing properly.
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m);
}