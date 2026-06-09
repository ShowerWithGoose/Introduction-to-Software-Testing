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
        if(c[i]=='-')  // @@ Missing: when expansion is not performed, the dash should also be copied to output. Currently, if left>=right or types don't match, the dash is skipped.
        {
            if(c[i-1]<c[i+1]) 
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ Incorrect: only checks lower bound of first and upper bound of second. Must ensure both are digits: c[i-1]>='0' && c[i-1]<='9' && c[i+1]>='0' && c[i+1]<='9'.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z')  // @@ Incorrect: only checks lower bound of first and upper bound of second. Must ensure both are lowercase letters: c[i-1]>='a' && c[i-1]<='z' && c[i+1]>='a' && c[i+1]<='z'.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z')  // @@ Incorrect: only checks lower bound of first and upper bound of second. Must ensure both are uppercase letters: c[i-1]>='A' && c[i-1]<='Z' && c[i+1]>='A' && c[i+1]<='Z'.
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