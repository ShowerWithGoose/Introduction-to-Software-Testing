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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [The condition is incorrect. It should check that both characters are within the same range (e.g., both lowercase, both uppercase, or both digits) and that the character after '-' is greater than the one before. The current condition only checks that s[i-1] is >= 'a' and s[i+1] <= 'z', which is too broad and does not ensure both are lowercase, uppercase, or digits. Additionally, it lacks a check for s[i+1] > s[i-1]. For input "B-e", s[i-1]='B' and s[i+1]='e', the condition s[i-1]>='A'&&s[i+1]<='Z' is false because 'e' is not <= 'Z', but the first part s[i-1]>='a'&&s[i+1]<='z' is also false because 'B' is not >= 'a'. However, due to operator precedence, the condition is evaluated as (s[i-1]>='a'&&s[i+1]<='z') || (s[i-1]>='A'&&s[i+1]<='Z') || (s[i-1]>='0'&&s[i+1]<='9'), which for "B-e" gives false for all, so it goes to else and copies '-', but the logic is flawed for other cases. The main issue is that the condition does not properly validate same-type and ordering, leading to incorrect expansion or no expansion when needed.]
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--;
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