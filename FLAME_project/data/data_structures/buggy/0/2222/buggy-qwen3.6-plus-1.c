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
            if((s[i-1]>='a'&&s[i-1]<='z' && s[i+1]>='a'&&s[i+1]<='z') || (s[i-1]>='A'&&s[i-1]<='Z' && s[i+1]>='A'&&s[i+1]<='Z') || (s[i-1]>='0'&&s[i-1]<='9' && s[i+1]>='0'&&s[i+1]<='9')) // @@ The original condition incorrectly checks types. For example, 'B' >= 'a' is false, but 'e' <= 'z' is true. The logic `s[i-1]>='a'&&s[i+1]<='z'` mixes the start and end characters' ranges, failing to ensure both are of the same specific type (both lowercase, both uppercase, or both digits). It should verify that the character before '-' and the character after '-' belong to the same category.
            {
                int c=s[i+1]-s[i-1];
                if (c > 0) // @@ Missing check if the expansion is valid (end char > start char). If c <= 0, no expansion should occur, and the '-' should be treated as a literal character. Without this, negative or zero loops might behave unexpectedly or skip outputting the hyphen correctly in invalid cases.
                {
                    int k=0;
                    while(k<c-1)
                    {
                        t[j]=s[i-1]+1+k;
                        k++;
                        j++;
                    }
                }
                else {
                     t[j] = s[i]; // @@ If expansion is invalid (c <= 0), the hyphen itself must be copied to the output.
                     j++;
                }
            }
            else {
                 t[j] = s[i]; // @@ If the characters around '-' are not of the same type, the hyphen must be copied to the output. The original code skips copying the hyphen in the else branch of the type check, leading to missing characters in the output.
                 j++;
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
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}