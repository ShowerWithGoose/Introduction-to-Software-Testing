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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') @@ // The condition is incorrect: it checks only one side of the range (e.g., s[i-1] >= 'a' but doesn't ensure s[i-1] <= 'z', and similarly for others). Also, it doesn't verify that both characters are of the same type.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; @@ // This decrements j unnecessarily, causing the next character to overwrite the last expanded character or skip a position incorrectly.
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
    int le=strlen(t); @@ // Using strlen(t) is unsafe because t may not be null-terminated at this point, leading to undefined behavior.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}