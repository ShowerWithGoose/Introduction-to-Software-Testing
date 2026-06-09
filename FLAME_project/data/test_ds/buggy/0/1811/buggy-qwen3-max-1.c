#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int m1;
    int n;
    fgets(s); // @@ [The fgets function requires three arguments: buffer, size, and stream. Here only one argument is provided, causing a compilation error. It should be fgets(s, sizeof(s), stdin);]
    n=strlen(s);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='-')
        {
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1]) // @@ [The condition is incorrect: it checks if s[i-1] >= '0' but does not check if s[i-1] <= '9'. Also, it checks s[i+1] <= '9' but not s[i+1] >= '0'. This may allow invalid ranges like '-9' or '0-:' to be processed.]
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
            if('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]) // @@ [Same issue as above: missing lower bound check for s[i-1] (should be s[i-1] >= 'A') and missing upper bound check for s[i+1] (should be s[i+1] <= 'Z'). Also, this allows mixed cases like 'A-z' to pass if ASCII values align incorrectly.]
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
            if('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1]) // @@ [Same issue: missing bounds checks. Should ensure both characters are in [a-z].]
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