#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int m1;
    int n;
    fgets(s); // @@ error: too few arguments to function 'fgets'; requires three arguments: buffer, size, and stream
    n=strlen(s);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='-')
        {
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--)
                    {
                        s[j+m1-2]=s[j];
                    }
                    for(int k=1;k<=m1-1;k++)
                    {
                        s[i-1+k]=s[i-1]+k;
                    }
                }
                else
                {
                    for(int j=i;j<=n-1;j++)
                    {
                        s[j]=s[j+1];
                    }
                }
            }
            if('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--)
                    {
                        s[j+m1-2]=s[j];
                    }
                    for(int k=1;k<=m1-1;k++)
                    {
                        s[i-1+k]=s[i-1]+k;
                    }
                }
                else
                {
                    for(int j=i;j<=n-1;j++)
                    {
                        s[j]=s[j+1];
                    }
                }
            }
            if('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1])
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--)
                    {
                        s[j+m1-2]=s[j];
                    }
                    for(int k=1;k<=m1-1;k++)
                    {
                        s[i-1+k]=s[i-1]+k;
                    }
                }
                else
                {
                    for(int j=i;j<=n-1;j++)
                    {
                        s[j]=s[j+1];
                    }
                }
            }
        }
        n=strlen(s);
    }
    puts(s);
}