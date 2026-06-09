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
        if(s[i]=='-') // @@ Missing check: must ensure s[i-1] and s[i+1] exist, are same type (letter/digit) and s[i-1] < s[i+1]; otherwise no expansion.
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Assumes s[i+1] > s[i-1] and same type; no handling for invalid cases (e.g., left>=right, different types). Also may access out-of-bounds.
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
    puts(m); // @@ m is not null-terminated; puts may print garbage or crash.
}