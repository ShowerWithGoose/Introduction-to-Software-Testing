#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, some compilers may not support it leading to compilation errors]
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ [Accessing c[i-1] when i=0 leads to undefined behavior (reading before start of array); also, no check that i>0 before accessing c[i-1]]
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should ensure both c[i-1] and c[i+1] are digits, but only checks lower bound for c[i-1] and upper bound for c[i+1]; e.g., 'a'-'9' could pass if 'a' > '0']
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: only checks c[i-1] >= 'a' and c[i+1] <= 'z', allowing mixed-type ranges like 'A'-'z' to incorrectly pass]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: incomplete type checking for uppercase letters]
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