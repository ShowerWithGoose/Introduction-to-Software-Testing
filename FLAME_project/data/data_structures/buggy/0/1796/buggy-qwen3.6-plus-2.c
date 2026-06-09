#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c);
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) 
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ The condition checks if the start is a digit and end is <= '9', but fails to ensure the end is also a digit (e.g., '0'-'A' would pass the second part if 'A' <= '9' was false, but logic is flawed for mixed types. More importantly, it doesn't check if they are BOTH digits. It should be c[i-1]>='0' && c[i-1]<='9' && c[i+1]>='0' && c[i+1]<='9'. The current check `c[i+1]<='9'` is insufficient to guarantee it's a digit if the first part is true, but actually the main issue is that it doesn't verify c[i+1] is a digit. For 'B-e', c[i-1]='B', c[i+1]='e'. 'B'>='0' is true. 'e'<='9' is false. So this block is skipped.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ Similar logic error. It checks if start is lowercase and end is <= 'z'. It does not check if end is >= 'a'. For 'B-e', 'B'>='a' is false. Skipped.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ Logic error. Checks if start is uppercase and end is <= 'Z'. For 'B-e', 'B'>='A' is true. 'e'<='Z' is false (since 'e' > 'Z' in ASCII). So this block is skipped.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            }
        }
        else
        {
            a[j]=c[i];
            j++;
        }
    }
    a[j]='\0';
    printf("%s",a);
    return 0;
}