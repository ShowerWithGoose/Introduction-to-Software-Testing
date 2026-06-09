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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') @@ // Condition is incorrect: it checks only lower bound for left char and upper bound for right char, but doesn't ensure both chars are of the same category (e.g., 'a' and 'Z' would incorrectly pass). Also missing parentheses around each category condition leading to wrong operator precedence.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; @@ // This decrements j after incrementing it in the loop, which may cause overwriting or skipping characters in some cases; logic for index management is flawed.
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
    int le=strlen(t); @@ // strlen(t) is unreliable because t is not null-terminated before this point, leading to undefined behavior.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); @@ // "%1c" is unnecessary; just "%c" suffices. Though not a compilation error, combined with uninitialized/undefined t content, output may be wrong.
        k++;
    }
    return 0;
}