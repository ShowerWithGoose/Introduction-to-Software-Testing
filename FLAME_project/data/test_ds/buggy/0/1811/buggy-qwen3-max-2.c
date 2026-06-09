#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int m1;
    int n;
    fgets(s); // @@ [The fgets function requires three arguments: buffer, size, and stream. Correct usage is fgets(s, sizeof(s), stdin).]
    n=strlen(s);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='-')
        {
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1]) // @@ [Incorrect condition: should check both s[i-1] >= '0' AND s[i+1] <= '9'. As written, it allows cases like s[i-1]='A' and s[i+1]='5' to pass the first part.]
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
            if('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]) // @@ [Same issue: missing lower bound check for s[i-1] (should be s[i-1] >= 'A') and upper bound for s[i+1] is checked but not lower bound (should also be s[i+1] >= 'A'). Also, this condition overlaps with digit case if input is malformed.]
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
            if('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1]) // @@ [Same issue: missing proper bounds checking. Should ensure s[i-1] >= 'a' AND s[i+1] >= 'a' AND s[i+1] <= 'z'.]
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