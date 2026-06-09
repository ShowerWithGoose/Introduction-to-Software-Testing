#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, the compilation error might be due to compiler settings rejecting 'gets'.]
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ [This condition does not check if both characters are of the same type (e.g., digit, lowercase, uppercase). It may incorrectly expand mixed-type ranges like 'a-5'.]
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should ensure both c[i-1] and c[i+1] are digits, but only checks lower bound for c[i-1] and upper bound for c[i+1]. For example, '9-0' would pass this check incorrectly if c[i-1]='9' and c[i+1]='0', but that's avoided by earlier c[i-1]<c[i+1]. However, case like 'a-9' could pass if 'a' < '9' (which it isn't in ASCII), but more critically, '0-Z' might not be caught properly. The real issue is missing validation that both ends belong to the same category.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: only checks c[i-1] >= 'a' and c[i+1] <= 'z', but doesn't ensure c[i+1] >= 'a' or c[i-1] <= 'z'. So something like 'a-Z' (if Z > a) wouldn't be caught here, but due to ASCII values, 'Z' < 'a', so maybe safe? However, 'm-z' is okay, but 'M-z' would have M < z, and if M is uppercase and z lowercase, this condition fails to reject it because c[i-1]='M' >= 'a' is false, so it skips. But what about 'a-Z'? c[i-1]='a' >= 'a' is true, c[i+1]='Z' <= 'z' is true, so it would incorrectly enter this block even though types differ. This is a critical logic error.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same problem: doesn't verify that c[i+1] >= 'A' or that c[i-1] <= 'Z'. Could allow mixed cases like 'A-z' to slip through if conditions align, though ASCII makes some combos less likely. But more importantly, fails to ensure both ends are uppercase.]
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