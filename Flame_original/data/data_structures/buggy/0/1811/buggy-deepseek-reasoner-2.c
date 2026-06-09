#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int m1;
    int n;
    fgets(s); // @@ [fgets requires three arguments: fgets(s, sizeof(s), stdin); this causes compilation error.]
    n=strlen(s);
    for(int i=1;i<n;i++) // @@ [Loop bound: when i == n-1, accessing s[i+1] is out of bounds; should be i < n-1 or add a check.]
    {
        if(s[i]=='-')
        {
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1]) // @@ [Missing lower bound for s[i+1] (should be >= '0') and upper bound for s[i-1] (should be <= '9'); allows non-digit characters to be treated as digits.]
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--) // @@ [Null terminator not moved; after shifting, the string lacks a null terminator at the new end, leading to undefined behavior when printing.]
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
            if('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]) // @@ [Missing lower bound for s[i+1] (should be >= 'A') and upper bound for s[i-1] (should be <= 'Z'); similar issue as above.]
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--) // @@ [Same null terminator issue.]
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
            if('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1]) // @@ [Missing lower bound for s[i+1] (should be >= 'a') and upper bound for s[i-1] (should be <= 'z'); similar issue.]
            {
                m1=s[i+1]-s[i-1];
                if(m1>1)
                {
                    for(int j=n-1;j>=i+1;j--) // @@ [Same null terminator issue.]
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
    return 0;
}