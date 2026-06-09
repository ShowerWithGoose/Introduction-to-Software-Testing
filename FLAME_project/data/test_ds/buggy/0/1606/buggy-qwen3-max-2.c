#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s);
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1; // @@ [This line assumes expansion is always valid and uses m[j-1], which may not be the correct previous character (e.g., when '-' is at start or after non-expanded chars). Also, it doesn't check if both sides are same type or if s[i+1] > s[i-1].]
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ [The output may be incorrect because invalid expansions (like 'B-e') are still expanded due to missing validation checks. Also, m is not null-terminated, which can cause undefined behavior in puts().]
}