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
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1; // @@ Error: When k=0, j may be 0, so m[j-1] accesses m[-1] which is out of bounds. Also, the initial value for expansion should be based on s[i-1], not m[j-1].
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