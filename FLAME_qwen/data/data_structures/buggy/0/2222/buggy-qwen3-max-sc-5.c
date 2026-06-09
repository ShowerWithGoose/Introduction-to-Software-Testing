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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [The condition incorrectly checks only the lower bound of the left character and upper bound of the right character without ensuring both characters belong to the same category (e.g., 'a'-'Z' would pass the first part falsely). Also, it doesn't verify that both characters are of the same type (both lowercase, both uppercase, or both digits).]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ [This decrements j after incrementing it in the loop, which may cause overwriting or skipping characters in the output array. It also doesn't account for proper indexing when appending expanded characters.]
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; // @@ [j is always incremented regardless of whether expansion occurred or not, which leads to incorrect indexing especially after handling a '-' with expansion. In the expansion block, j is modified inside the loop and then decremented, but then incremented again here, causing misalignment.]
    }
    t[j]=s[l-1];
    int le=strlen(t); // @@ [strlen(t) is unreliable because t is not null-terminated. The program fills t manually without setting a '\0', so strlen may read beyond intended data, leading to undefined behavior.]
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); // @@ [Using "%1c" is unnecessary and unusual; "%c" suffices. However, this is not the main error. The real issue is that t may contain garbage beyond the written characters due to missing null termination, and le may be incorrect.]
        k++;
    }
    return 0;
}