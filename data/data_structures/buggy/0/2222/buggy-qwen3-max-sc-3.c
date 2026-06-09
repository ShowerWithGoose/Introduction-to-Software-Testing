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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [The condition incorrectly checks only one side of the range; it should ensure both characters are of the same type and within valid ranges, e.g., (s[i-1] >= 'a' && s[i+1] <= 'z' && s[i-1] <= 'z' && s[i+1] >= 'a')]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ [This decrements j unnecessarily, causing potential overwriting or skipping of characters in the next iteration]
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; // @@ [j is always incremented even when expansion occurs and j was already adjusted, leading to gaps or incorrect indexing in t]
    }
    t[j]=s[l-1];
    int le=strlen(t); // @@ [strlen(t) is unreliable because t may not be null-terminated, leading to undefined behavior]
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); // @@ [Using "%1c" is unnecessary and non-standard; "%c" suffices. Also, if t is not properly null-terminated, le may be wrong, causing garbage output]
        k++;
    }
    return 0;
}