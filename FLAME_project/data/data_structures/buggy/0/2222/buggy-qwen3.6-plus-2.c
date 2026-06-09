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
            if((s[i-1]>='a'&&s[i-1]<='z' && s[i+1]>='a'&&s[i+1]<='z') || (s[i-1]>='A'&&s[i-1]<='Z' && s[i+1]>='A'&&s[i+1]<='Z') || (s[i-1]>='0'&&s[i-1]<='9' && s[i+1]>='0'&&s[i+1]<='9')) // @@ [The original condition incorrectly checks types. For example, 'B' >= 'a' is false, but 'e' <= 'z' is true. The logic must ensure BOTH characters are of the same specific type (lowercase, uppercase, or digit). Also need to check if start < end.]
            {
                int c=s[i+1]-s[i-1];
                if (c > 0) // @@ [Expansion should only happen if the character after '-' is greater than the one before. If c <= 0, we should treat it as invalid expansion and output original chars.]
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
                     t[j] = s[i]; // @@ [If expansion condition fails (types mismatch or start >= end), output the '-' character itself]
                     j++;
                }
            }
            else {
                 t[j] = s[i]; // @@ [If types do not match, output the '-' character itself]
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
    t[j+1] = '\0'; // @@ [The string t must be null-terminated before using strlen or printing as a string. The original code did not terminate t, leading to undefined behavior or garbage output.]
    int le=strlen(t);
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}