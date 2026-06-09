#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, the problem expects input via 'scanf' or safer alternatives.]
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ [This condition does not check if both surrounding characters are of the same type (e.g., digit, lowercase, uppercase). It may incorrectly expand mixed-type ranges like 'a-Z'.]
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should ensure BOTH c[i-1] and c[i+1] are digits. Current code allows cases like '0-Z' to pass if c[i+1] <= '9' is false but c[i-1] >= '0' is true, leading to logic errors. Also, missing upper bound check on c[i-1] and lower bound on c[i+1].]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: must verify both ends are lowercase letters. Current condition fails to check c[i+1] >= 'a' and c[i-1] <= 'z'.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: must verify both ends are uppercase letters. Missing checks for c[i+1] >= 'A' and c[i-1] <= 'Z'.]
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