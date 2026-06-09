#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, 'gets' is not available, leading to a compilation error.]
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) 
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should check that BOTH c[i-1] and c[i+1] are digits, but this only checks c[i-1] >= '0' and c[i+1] <= '9', allowing invalid mixes like 'a'-'9'. Also, no check that c[i-1] <= '9' or c[i+1] >= '0'.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: should ensure both ends are lowercase letters. This allows cases like 'A'-'z' to pass if c[i-1] >= 'a' (false for 'A') but logic is flawed; also missing upper bound on c[i-1] and lower bound on c[i+1].]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: incomplete range validation for uppercase letters.]
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