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

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [The condition checks if the left char is >= '0' and right char <= '9', but does not ensure both are digits. For example, 'B-e' could pass if 'e' <= '9' (which it isn't), but more critically, it doesn't verify that both ends are of the same category. Also, it should check that both characters are digits, i.e., c[i-1] <= '9' && c[i+1] >= '0'.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: only checks lower bound on left and upper bound on right. Should ensure both are lowercase letters, i.e., c[i-1] <= 'z' && c[i+1] >= 'a'. Without this, mixed cases like 'B-e' might incorrectly trigger expansion if conditions partially match.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same issue: incomplete range validation. Must ensure both characters are uppercase letters. Current condition allows invalid combinations like 'B-e' to possibly fall through or behave unexpectedly.]
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