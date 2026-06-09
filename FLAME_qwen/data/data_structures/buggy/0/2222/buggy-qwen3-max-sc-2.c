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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [The condition checks only one side of the range (e.g., s[i-1] >= 'a' but not <= 'z'), so it incorrectly allows mixed-type expansions like 'a-Z'. It should ensure both characters are in the same category and valid. Also, operator precedence issue: && has higher precedence than ||, but parentheses are missing to group each type check properly.]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ [This decrements j after incrementing it in the loop, which may cause overwriting or skipping characters in t[]. The logic for managing the output buffer index is flawed.]
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; // @@ [j is always incremented, even when '-' is processed and characters are added in the loop. This leads to gaps or overwrites in the output array t[].]
    }
    t[j]=s[l-1];
    int le=strlen(t); // @@ [strlen(t) is unreliable because t is not null-terminated before this point. This can lead to undefined behavior or incorrect length calculation.]
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); // @@ [Using "%1c" is unnecessary and non-standard; "%c" suffices. Though not a compilation error, it's odd formatting. However, the real issue is that t may contain uninitialized/garbage values due to incorrect indexing, leading to wrong output.]
        k++;
    }
    return 0;
}