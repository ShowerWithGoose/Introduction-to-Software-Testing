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
            if(c[i-1]<c[i+1]) // @@ [This condition does not check if both surrounding characters are of the same valid type (digit, lowercase, uppercase). It may incorrectly expand across types like 'a'-'Z'.]
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Incorrect condition: should ensure BOTH c[i-1] AND c[i+1] are digits. Current code allows c[i-1]='/' (ASCII 47) and c[i+1]='5', which passes but shouldn't.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: must verify BOTH ends are lowercase letters. e.g., c[i-1]='z', c[i+1]='5' would skip this, but c[i-1]='0', c[i+1]='z' might incorrectly enter if other conditions fail.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: must check both characters are uppercase. Current logic only checks lower bound of left and upper bound of right.]
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