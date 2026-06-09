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
            // @@ The code fails to check if the characters before and after '-' are of the same type (both lowercase, both uppercase, or both digits) and if the start character is less than the end character. It blindly expands any range, causing "B-e" to be expanded incorrectly.
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1;
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