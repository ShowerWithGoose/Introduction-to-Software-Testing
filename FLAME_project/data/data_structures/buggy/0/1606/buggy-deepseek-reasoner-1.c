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
            for(k=0;k<s[i+1]-s[i-1]-1;k++)@@ // Error: No check for same character type and left<right; also may access out-of-bounds when i==0 or s[i+1]=='\0'
            {
                m[j]=m[j-1]+1;@@ // Error: Incorrect assignment; should be m[j]=s[i-1]+1+k; potential out-of-bounds when j==0
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