#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int m1;
    int n;
    fgets(s); // @@ [Error: fgets requires three arguments: (buffer, size, stream). Should be fgets(s, sizeof(s), stdin).]
    n=strlen(s);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='-')
        {
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1]) // @@ [Error: The condition '0'<=s[i-1] is always true because '0' is a character literal with ASCII value 48, and s[i-1] is a char. The intended check is s[i-1]>='0' && s[i+1]<='9'. Also, the condition s[i-1]<s[i+1] is correct but the range check is wrong.]
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
            if('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]) // @@ [Error: Same issue as above; should be s[i-1]>='A' && s[i+1]<='Z'.]
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
            if('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1]) // @@ [Error: Same issue; should be s[i-1]>='a' && s[i+1]<='z'.]
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