#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ Using gets() is unsafe and deprecated; may cause buffer overflow and compilation error in strict C11.
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) // @@ Loop processes up to the end; when i is the last index, accessing c[i+1] is '\0' and dash at end will not be output.
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ Accesses c[i-1] without checking i>0; causes undefined behavior when i=0. Also condition alone does not ensure same type.
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ Only checks left >= '0' and right <= '9'; should verify both are digits. Missing else for dash when no expansion occurs.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ Similar issue: incomplete type check and missing dash output when not matched.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ Similar issue.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            } // @@ Missing else: when the condition c[i-1]<c[i+1] is false or when type conditions fail, the dash should be output as is, but it is not.
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