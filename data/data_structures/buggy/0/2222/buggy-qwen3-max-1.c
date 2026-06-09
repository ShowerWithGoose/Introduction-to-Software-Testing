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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') @@ // Condition logic is incorrect: it checks only lower bound of left char and upper bound of right char, not that both are in the same category. Also missing parentheses around each category condition leading to wrong operator precedence.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; @@ // This decrements j unnecessarily; after filling expansion chars, j should point to next empty slot, but this breaks alignment for next character.
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; @@ // j is always incremented, even when '-' was expanded and j was already advanced in the loop; this causes skipping or overwriting.
    }
    t[j]=s[l-1];
    int le=strlen(t); @@ // strlen(t) is unsafe because t may not be null-terminated, leading to undefined behavior.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); @@ // %1c is unnecessary; just %c suffices. More critically, if t isn't properly null-terminated or le is wrong, output may be corrupted.
        k++;
    }
    return 0;
}