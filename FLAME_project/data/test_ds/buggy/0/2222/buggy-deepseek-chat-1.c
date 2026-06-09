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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ [Error: The condition does not properly check that both characters are of the same type and within the same range. For example, 'B' and 'e' are both letters but different cases, so they should not be expanded. The condition should use && to combine range checks for each type separately, e.g., (s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z') || ... Also, the condition lacks a check that s[i+1] > s[i-1] (the character after '-' must be greater than the one before).]
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