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

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [This condition checks if the left char is >= '0' and right char <= '9', but does not ensure both are digits. For example, 'B-e' would have c[i-1]='B' (>= '0') and c[i+1]='e' (<= '9' is false), but more critically, it doesn't verify that both characters belong to the same category. Also, '0' <= char <= '9' must hold for both ends.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: only checks lower bound on left and upper bound on right. Should check both ends are in [a-z]. For example, 'B-e' has c[i-1]='B' which is not >= 'a', so this fails correctly, but a case like 'a-Z' might incorrectly pass one side. However, the real problem is that it doesn't confirm both chars are lowercase.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same flaw: doesn't ensure both characters are uppercase letters. Must check c[i-1] <= 'Z' and c[i+1] >= 'A' as well. Without full range validation, mixed-type cases may be incorrectly expanded or skipped improperly.]
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