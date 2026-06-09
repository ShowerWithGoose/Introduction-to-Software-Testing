#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ gets() is removed in C11 standard, causing compilation errors in modern environments; use fgets() or scanf() instead.
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ Accessing c[i-1] when i=0 causes out-of-bounds memory access; also fails to verify c[i+1] is not '\0'.
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ Incorrect range validation; only checks c[i-1]>='0' and c[i+1]<='9', allowing mixed types like 'a-9'. Should verify both characters are digits.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ Incorrect range validation; same issue as above, allows mixed types. Should verify both characters are lowercase letters.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ Incorrect range validation; same issue as above, allows mixed types. Should verify both characters are uppercase letters.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            } // @@ Missing else block to copy '-' to the output array when expansion conditions are not met, causing '-' to be lost in the output.
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