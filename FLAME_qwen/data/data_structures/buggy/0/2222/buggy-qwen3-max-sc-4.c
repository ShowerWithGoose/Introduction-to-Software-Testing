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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [The condition checks only one side of the range (e.g., s[i-1] >= 'a' but not <= 'z'), so it incorrectly allows mixed-type expansions like 'a-Z'. Also, operator precedence issue: && has higher precedence than ||, but parentheses are missing to group each type check properly.]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ [This decrements j after writing expanded characters, which may overwrite or skip positions in t[]. It should not decrement j here because j was correctly advanced during expansion.]
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; // @@ [j is always incremented, even when expansion occurs and j was already updated inside the expansion block. This causes skipping or overwriting in t[].]
    }
    t[j]=s[l-1];
    int le=strlen(t); // @@ [strlen(t) is unsafe here because t may not be null-terminated, leading to undefined behavior. The array t is filled manually without ensuring a '\0' at the end before calling strlen().]
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); // @@ [Using "%1c" is unnecessary and non-standard for simple character output; "%c" suffices. However, this is not a compilation error. The real issue is that t might not be properly constructed or null-terminated, causing incorrect output.]
        k++;
    }
    return 0;
}