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

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [This condition checks if the left char is >= '0' AND right char <= '9', but it doesn't ensure both are digits. For example, 'B-e' would have c[i-1]='B' (not >= '0') so this fails, but the next conditions also fail incorrectly because they use similar flawed logic. Also, it doesn't verify that both characters are of the same type.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: checks left >= 'a' and right <= 'z', but doesn't ensure both are lowercase letters. For instance, 'a-Z' would pass left >= 'a' and right <= 'z' is false, but 'A-z' might incorrectly pass one side. More critically, it allows mixed cases like 'a-Z' to possibly fall through or be mishandled. Also, it should check that BOTH are in [a-z].]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same flaw: doesn't ensure both characters are uppercase letters. It only checks left >= 'A' and right <= 'Z', which could allow invalid pairs like 'A-z' (if z were <= 'Z', which it isn't, but logic is still wrong). Correct approach is to check both ends belong to same category.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            }
            else // @@ [Missing else case: when c[i-1] >= c[i+1], the '-' should be copied as-is, but current code skips copying '-' entirely in this case. Also, even when expansion conditions fail (like mixed types), the '-' and surrounding chars aren't handled properly.]
            {
                a[j] = c[i]; // @@ [This block is missing! The original code does not handle the case where '-' is present but shouldn't be expanded — it just skips adding anything for '-', leading to omission of '-' in output.]
                j++;
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