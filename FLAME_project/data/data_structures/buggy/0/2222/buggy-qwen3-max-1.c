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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') @@ // Incorrect condition: checks only lower bound of left char and upper bound of right char without ensuring both are same type and valid range; e.g., 'B' >= 'A' is true and 'e' <= 'z' is true, so "B-e" incorrectly passes this check.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; @@ // Unnecessary decrement of j causes overwriting or skipping next character; also logic fails to skip the part after '-' properly.
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
    int le=strlen(t); @@ // Using strlen on t is unsafe because t may not be null-terminated yet, leading to undefined behavior.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}