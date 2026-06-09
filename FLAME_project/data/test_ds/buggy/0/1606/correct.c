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
        if(s[i]=='-'&&((s[i+1]<='Z'&&s[i-1]>='A'&&s[i-1]<=s[i+1])||(s[i+1]<='9'&&s[i-1]>='0'&&s[i-1]<=s[i+1])||(s[i+1]<='z'&&s[i-1]>='a'&&s[i-1]<=s[i+1])))
        {
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

