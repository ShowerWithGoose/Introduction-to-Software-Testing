#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to a compilation error.]
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) 
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should check that BOTH c[i-1] and c[i+1] are digits, but this only checks lower bound for c[i-1] and upper bound for c[i+1]. Also, does not ensure they are of the same type. However, this is a logic error, not the cause of the compilation error. The primary compilation error is due to 'gets'.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: condition is incorrect. Should verify both ends are lowercase letters. But again, not the cause of compilation failure.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: incorrect bounds checking. Not the cause of compilation error.]
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