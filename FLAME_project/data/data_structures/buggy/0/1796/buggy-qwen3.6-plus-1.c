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

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ The condition checks if the start is a digit and end is <= '9', but fails to verify that the end character is also >= '0' or that they are both digits. More importantly, it doesn't check if they are of the *same* type strictly before expansion logic applies in a way that prevents mixed types like 'B' and 'e' from passing previous checks if logic was flawed, but here the specific error is that this block executes for digits. However, the main issue for "B-e" is that it falls through to the else block below because 'B' is not >= '0' (it is, but 'e' is not <= '9'). Wait, 'B' is 66, '0' is 48. 'B' >= '0' is true. 'e' is 101, '9' is 57. 'e' <= '9' is false. So it goes to next else if.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') 
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') 
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
            a[j]=c[i]; // @@ When c[i] is '-', it is not copied to output array 'a' if expansion conditions are met or not met correctly. If expansion is NOT performed (like in B-e), the '-' character itself is skipped because it's handled in the 'if(c[i]=='-')' block but never added to 'a' if the inner conditions don't trigger an expansion write, or even if they do, the '-' is replaced. In the case of "B-e", the conditions for expansion fail (mixed case), so nothing is written to 'a' for the '-', and the loop continues. The 'else' branch only handles non-'-' characters. Thus, the '-' is lost.
            j++;
        }
    }
    a[j]='\0';
    printf("%s",a);
    return 0;
}