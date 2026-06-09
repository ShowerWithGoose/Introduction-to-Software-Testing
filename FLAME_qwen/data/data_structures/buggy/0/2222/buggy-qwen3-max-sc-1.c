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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') @@ [The condition is incorrect: it checks only lower bound of left char and upper bound of right char, but doesn't ensure both chars are of the same type or that the left char is within its valid range. For example, 'a'-'Z' would incorrectly pass because 'a'>='a' and 'Z'<='Z', even though they're different types. Also missing parentheses around each type condition leads to wrong operator precedence.]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; @@ [This decrements j unnecessarily; after filling expanded characters, j should point to next empty slot, but this breaks alignment for next character.]
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++; @@ [When expansion occurs, j was already incremented in the loop and then decremented above; this extra increment causes skipping or overwriting. Also, when '-' is processed and expansion happens, the current '-' is not output, but the logic doesn't account for proper indexing consistently.]
    }
    t[j]=s[l-1];
    int le=strlen(t); @@ [strlen(t) is undefined behavior because t is not null-terminated. The code fills t with characters but never adds '\0', so strlen may read beyond intended data.]
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]); @@ [Using "%1c" is unnecessary and non-standard; just "%c" suffices. However, this isn't a compilation error. The real issue causing potential runtime/undefined behavior is lack of null termination in t.]
        k++;
    }
    return 0;
}