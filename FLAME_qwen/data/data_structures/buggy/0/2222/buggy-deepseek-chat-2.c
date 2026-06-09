#include<stdio.h>
#include<string.h>
char s[100000];
char t[100000];
int main()
{
    scanf("%s",s);
    int i,j;
    t[0]=s[0];
    i=j=1;
    int l=strlen(s);
    while(i<l-1)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ The condition is incorrect: it should check that both characters are within the same range, not just that the first is >= start and the second is <= end. For example, 'a' <= s[i-1] <= 'z' AND 'a' <= s[i+1] <= 'z' should be checked separately. Also missing parentheses around each range check.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ This decrement of j is incorrect; it causes the next character to overwrite the last expanded character. The j should not be decremented here.
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++;
    }
    t[j]=s[l-1];
    int le=strlen(t);
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); // @@ The format specifier "%1c" is incorrect; it should be "%c". "%1c" may cause undefined behavior or incorrect output.
        k++;
    }
    return 0;
}